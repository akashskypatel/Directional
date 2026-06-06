from __future__ import annotations

import contextlib
import os
from collections.abc import Iterator

from setuptools import build_meta as _build_meta


def _get_setting(config_settings: dict[str, object] | None, *keys: str) -> object | None:
    if not config_settings:
        return None
    for key in keys:
        if key in config_settings:
            return config_settings[key]
    return None


def _normalize_bool(value: object) -> str | None:
    if value is None:
        return None
    if isinstance(value, (list, tuple)):
        if not value:
            return None
        value = value[-1]
    text = str(value).strip().lower()
    if text in {"1", "on", "true", "yes"}:
        return "1"
    if text in {"0", "off", "false", "no"}:
        return "0"
    raise ValueError(f"Invalid boolean build setting: {value!r}")


@contextlib.contextmanager
def _apply_directional_settings(config_settings: dict[str, object] | None) -> Iterator[None]:
    mappings = {
        "DIRECTIONAL_USE_GMP": _normalize_bool(
            _get_setting(config_settings, "use-gmp", "directional.use-gmp")
        ),
        "DIRECTIONAL_AUTO_INSTALL_GMP": _normalize_bool(
            _get_setting(config_settings, "auto-install-gmp", "directional.auto-install-gmp")
        ),
        "DIRECTIONAL_ENABLE_CUDA": _normalize_bool(
            _get_setting(
                config_settings,
                "enable-cuda",
                "directional.enable-cuda",
                "enable-cude",
                "directional.enable-cude",
            )
        ),
    }
    previous: dict[str, str | None] = {key: os.environ.get(key) for key in mappings}
    try:
        for key, value in mappings.items():
            if value is not None:
                os.environ[key] = value
        yield
    finally:
        for key, value in previous.items():
            if value is None:
                os.environ.pop(key, None)
            else:
                os.environ[key] = value


def get_requires_for_build_wheel(config_settings=None):
    with _apply_directional_settings(config_settings):
        return _build_meta.get_requires_for_build_wheel(config_settings)


def get_requires_for_build_sdist(config_settings=None):
    with _apply_directional_settings(config_settings):
        return _build_meta.get_requires_for_build_sdist(config_settings)


def prepare_metadata_for_build_wheel(metadata_directory, config_settings=None):
    with _apply_directional_settings(config_settings):
        return _build_meta.prepare_metadata_for_build_wheel(metadata_directory, config_settings)


def build_wheel(wheel_directory, config_settings=None, metadata_directory=None):
    with _apply_directional_settings(config_settings):
        return _build_meta.build_wheel(wheel_directory, config_settings, metadata_directory)


def build_sdist(sdist_directory, config_settings=None):
    with _apply_directional_settings(config_settings):
        return _build_meta.build_sdist(sdist_directory, config_settings)
