#include <directional/io/PolygonalWriteOFF.h>

#include <fstream>

namespace hedra {

bool polygonal_write_OFF(const std::string& str,
                                      const Eigen::MatrixXd& V,
                                      const Eigen::VectorXi& D,
                                      const Eigen::MatrixXi& F)
  {

    using namespace std;
    using namespace Eigen;
    ofstream FileHandle;
    FileHandle.open(str);
    if (!FileHandle.is_open())
      return false;

    int precision = 9; // Set precision to 5 decimal places
    Eigen::IOFormat resFormat(precision, 0, " ", "\n");
    FileHandle<<"OFF"<<endl<<V.rows()<<" "<<F.rows()<<" 0"<<endl;
    FileHandle<<V.format(resFormat)<<endl;
    MatrixXi FD(D.rows(), D.cols()+F.cols());
    FD<<D, F;
    for (int i=0;i<F.rows();i++)
      FileHandle<<FD.block(i,0,1,D(i)+1)<<endl;
    FileHandle.close();
    return true;
  }

} // namespace hedra
