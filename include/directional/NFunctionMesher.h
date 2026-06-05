//
// Created by Amir Vaxman on 20.04.24.
//

#ifndef DIRECTIONAL_N_FUNCTION_MESHER
#define DIRECTIONAL_N_FUNCTION_MESHER

#include <set>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <chrono>
#include <utility>
#include <Eigen/Sparse>
#include <Eigen/Dense>
#include <directional/exact_geometric_definitions.h>
#include <directional/dcel.h>
#include <directional/setup_mesher.h>

namespace directional{

class NFunctionMesher {
public:
    
    const TriMesh& origMesh;
    const MesherData& mData;
    
    struct SegmentData{
        bool isFunction;
        int origHalfedge;
        int origNFunctionIndex;  //the original parameteric function assoicated with this edge
        int lineInPencil;
        std::set<ENumber> intParams;
        //double prescribedAngle;  //the actual prescribed angle
        
        SegmentData():isFunction(false), origHalfedge(-1), origNFunctionIndex(-1),  lineInPencil(-1), intParams(){} //prescribedAngle(-1.0){}
    };
    
    struct VData{
        Eigen::RowVector3d coords;
        EVector3 eCoords;
    };
    
    typedef DCEL<VData,  SegmentData, bool, bool> FunctionDCEL;
    FunctionDCEL genDcel;
    
    //halfedge quantities
    Eigen::MatrixXd NFunction;
    std::vector<std::vector<ENumber>> exactNFunction;
    
    
    //mesh generation functions found in generate_mesh.h
    void arrange_on_triangle(const std::vector<EVector2>& triangle,
                             const std::vector<std::pair<int, bool>>& triangleData,
                             const std::vector<LinePencil>& linePencils,
                             const std::vector<int>& linePencilData,
                             std::vector<EVector2>& V,
                             FunctionDCEL& triDcel);
    
    void segment_arrangement(const std::vector<Segment2>& segments,
                             const std::vector<SegmentData>& data,
                             const Eigen::Matrix<ENumber, Eigen::Dynamic ,2> I2dts,
                             const Eigen::Matrix<ENumber, Eigen::Dynamic ,1> t00s,
                             std::vector<EVector2>& V,
                             FunctionDCEL& triDcel);
    
    void generate_mesh(const unsigned long Resolution);
    
    std::vector<int> TransVertices;
    std::vector<int> InStrip;
    std::vector<std::set<int> > VertexChains;
    
    
    struct MergeData {
        const bool operator()(const int &v1, const int &v2) const { return v1; }
    };
    
    
    void TestUnmatchedTwins();
    
    struct PointPair{
        int Index1, Index2;
        ENumber Distance;
        
        PointPair(int i1, int i2, const EVector3& d):Index1(i1), Index2(i2){
            Distance=d.max_abs();
        }
        ~PointPair(){}
        
        const bool operator<(const PointPair& pp) const {
            if (Distance>pp.Distance) return false;
            if (Distance<pp.Distance) return true;
            
            if (Index1>pp.Index1) return false;
            if (Index1<pp.Index1) return true;
            
            if (Index2>pp.Index2) return false;
            if (Index2<pp.Index2) return true;
            
            return false;
            
        }
    };
    
    std::vector<std::pair<int,int>> FindVertexMatch(const bool verbose, std::vector<EVector3>& Set1, std::vector<EVector3>& Set2)
    {
        std::set<PointPair> PairSet;
        for (int i=0;i<Set1.size();i++)
            for (int j=0;j<Set2.size();j++)
                PairSet.insert(PointPair(i,j,Set1[i]-Set2[j]));
        
        assert (Set1.size()==Set2.size() && "NFunctionMesher::FindVertexMatch(): The two sets are of different sizes!! ");
        
        //adding greedily legal connections until graph is full
        std::vector<bool> Set1Connect(Set1.size());
        std::vector<bool> Set2Connect(Set2.size());
        
        std::vector<std::pair<int, int> > Result;
        
        for (int i=0;i<Set1.size();i++)
            Set1Connect[i]=false;
        
        for (int i=0;i<Set2.size();i++)
            Set2Connect[i]=false;
        
        /*if (Set1.size()!=Set2.size())
         int kaka=9;*/
        
        int NumConnected=0;
        
        //categorically match both ends
        
        Result.push_back(std::pair<int, int>(0,0));
        Result.push_back(std::pair<int, int>(Set1.size()-1,Set2.size()-1));
        for (std::set<PointPair>::iterator ppi=PairSet.begin();ppi!=PairSet.end();ppi++)
        {
            PointPair CurrPair=*ppi;
            //checking legality - if any of one's former are connected to ones latters or vice versa
            bool FoundConflict=false;
            for (int i=0;i<Result.size();i++){
                if (((Result[i].first>CurrPair.Index1)&&(Result[i].second<CurrPair.Index2))||
                    ((Result[i].first<CurrPair.Index1)&&(Result[i].second>CurrPair.Index2))){
                    FoundConflict=true;
                    break;
                }
            }
            
            if (FoundConflict)
                continue;
            
            //if both are already matched, this matching is redundant
            if ((Set1Connect[CurrPair.Index1])&&(Set2Connect[CurrPair.Index2]))
                continue;  //there is no reason for this matching
            
            //otherwise this edge is legal, so add it
            Result.push_back(std::pair<int, int>(CurrPair.Index1, CurrPair.Index2));
            if (!Set1Connect[CurrPair.Index1]) NumConnected++;
            if (!Set2Connect[CurrPair.Index2]) NumConnected++;
            Set1Connect[CurrPair.Index1]=Set2Connect[CurrPair.Index2]=true;
            /*if (NumConnected==Set1.size()+Set2.size())
             break;  //all nodes are connected*/
        }
        
        for (int i=0;i<Set1.size();i++)
            if ((!Set1Connect[i])&&(verbose))
                std::cout<< "[Directional::NFunctionMesher::FindVertexMatch()]: "<<"Relative Vertex "<<i<<" in Set1 is unmatched!"<<std::endl;
        
        for (int i=0;i<Set2.size();i++)
            if ((!Set2Connect[i])&&(verbose))
                std::cout<< "[Directional::NFunctionMesher::FindVertexMatch()]: "<<"Relative Vertex "<<i<<" in Set2 is unmatched!"<<std::endl;
        
        /*if (NumConnected!=Set1.size()+Set2.size())
         int kaka=9;*/
        
        if (verbose){
            for (int i=0;i<Result.size();i++){
                if (squaredDistance(Set1[Result[i].first],Set2[Result[i].second])>ENumber(0)){
                    std::cout<< "[Directional::NFunctionMesher::FindVertexMatch()]: "<<"("<<Result[i].first<<","<<Result[i].second<<") with dist "<<squaredDistance(Set1[Result[i].first],Set2[Result[i].second]).to_double()<<std::endl;
                    std::cout<< "[Directional::NFunctionMesher::FindVertexMatch()]: "<<"Distance is abnormally not zero!"<<std::endl;
                }
            }
        }
        
        
        return Result;
        
    }

    struct SimplifyScratch {
        int maxOrigHE = -1;
        std::vector<bool> visitedOrig;
        std::vector<std::vector<int>> boundEdgeCollect1;
        std::vector<std::vector<int>> boundEdgeCollect2;
        std::vector<std::vector<int>> vertexSets1;
        std::vector<std::vector<int>> vertexSets2;
        std::vector<std::pair<int, int>> vertexMatches;
        std::vector<bool> marked;
        std::vector<bool> isPureTriangle;
        std::vector<bool> isBoundary;
        std::vector<bool> isEar;
        std::vector<int> valences;
    };

    bool should_log_progress(const int index, const int total) const
    {
        if (!mData.verbose || total <= 0)
            return false;
        if (index == 0 || index + 1 == total)
            return true;
        const int step = std::max(1, total / 10);
        return ((index + 1) % step) == 0;
    }

    void log_progress(const char* label, const int index, const int total) const
    {
        if (!should_log_progress(index, total))
            return;
        std::cout << "[Directional::NFunctionMesher::simplify_mesh()]: " << label << ": "
                  << (index + 1) << "/" << total << std::endl;
    }

    bool run_initial_consistency_check()
    {
        return genDcel.check_consistency(mData.verbose, false, false, false);
    }

    void scan_original_halfedge_range(SimplifyScratch& scratch)
    {
        scratch.maxOrigHE = -3276700;
        for (int i = 0; i < genDcel.halfedges.size(); i++)
            scratch.maxOrigHE = std::max(scratch.maxOrigHE, genDcel.halfedges[i].data.origHalfedge);
    }

    bool visit_boundary_seeds(SimplifyScratch& scratch)
    {
        scratch.visitedOrig.assign(scratch.maxOrigHE + 1, false);
        for (int i = 0; i < genDcel.halfedges.size(); i++) {
            log_progress("boundary seed scan", i, static_cast<int>(genDcel.halfedges.size()));
            if (genDcel.halfedges[i].data.origHalfedge < 0)
                continue;
            if (scratch.visitedOrig[genDcel.halfedges[i].data.origHalfedge])
                continue;

            const int hebegin = i;
            int heiterate = hebegin;
            do {
                scratch.visitedOrig[genDcel.halfedges[heiterate].data.origHalfedge] = true;
                if (!genDcel.walk_boundary(heiterate, mData.verbose, "[Directional::DCEL] walk_boundary()")) {
                    if (mData.verbose) {
                        std::cout << "[Directional::NFunctionMesher::simplify_mesh()]: boundary seed walk failed for seed "
                                  << i << " at halfedge " << heiterate << std::endl;
                    }
                    break;
                }
            } while (heiterate != hebegin);
        }

        return true;
    }

    void collect_boundary_strips(SimplifyScratch& scratch)
    {
        scratch.boundEdgeCollect1.assign(scratch.maxOrigHE + 1, std::vector<int>());
        scratch.boundEdgeCollect2.assign(scratch.maxOrigHE + 1, std::vector<int>());
        scratch.marked.assign(genDcel.halfedges.size(), false);

        for (int i = 0; i < genDcel.halfedges.size(); i++) {
            log_progress("boundary strip collection", i, static_cast<int>(genDcel.halfedges.size()));
            if ((genDcel.halfedges[i].data.origHalfedge < 0) || (scratch.marked[i]))
                continue;

            int PrevOrig;
            int CurrEdge = i;
            do {
                PrevOrig = genDcel.halfedges[CurrEdge].data.origHalfedge;
                genDcel.walk_boundary(CurrEdge);
            } while (PrevOrig == genDcel.halfedges[CurrEdge].data.origHalfedge);

            const int BeginEdge = CurrEdge;
            std::vector<std::pair<int, int>> CurrEdgeCollect;
            do {
                CurrEdgeCollect.push_back(std::pair<int, int>(genDcel.halfedges[CurrEdge].data.origHalfedge, CurrEdge));
                scratch.marked[CurrEdge] = true;
                genDcel.walk_boundary(CurrEdge);
            } while (CurrEdge != BeginEdge);

            PrevOrig = -1000;
            bool In1 = false;
            for (int j = 0; j < CurrEdgeCollect.size(); j++) {
                if (CurrEdgeCollect[j].first != PrevOrig)
                    In1 = scratch.boundEdgeCollect1[CurrEdgeCollect[j].first].empty();

                if (In1)
                    scratch.boundEdgeCollect1[CurrEdgeCollect[j].first].push_back(CurrEdgeCollect[j].second);
                else
                    scratch.boundEdgeCollect2[CurrEdgeCollect[j].first].push_back(CurrEdgeCollect[j].second);
                PrevOrig = CurrEdgeCollect[j].first;
            }
        }
    }

    void build_boundary_vertex_sets(SimplifyScratch& scratch)
    {
        scratch.vertexSets1.assign(scratch.maxOrigHE + 1, std::vector<int>());
        scratch.vertexSets2.assign(scratch.maxOrigHE + 1, std::vector<int>());

        for (int i = 0; i < scratch.maxOrigHE + 1; i++) {
            log_progress("vertex set build", i, scratch.maxOrigHE + 1);
            for (int j = 0; j < scratch.boundEdgeCollect1[i].size(); j++)
                scratch.vertexSets1[i].push_back(genDcel.halfedges[scratch.boundEdgeCollect1[i][j]].vertex);

            if (scratch.boundEdgeCollect1[i].size() > 0)
                scratch.vertexSets1[i].push_back(genDcel.halfedges[genDcel.halfedges[scratch.boundEdgeCollect1[i][scratch.boundEdgeCollect1[i].size() - 1]].next].vertex);

            for (int j = 0; j < scratch.boundEdgeCollect2[i].size(); j++)
                scratch.vertexSets2[i].push_back(genDcel.halfedges[scratch.boundEdgeCollect2[i][j]].vertex);

            if (scratch.boundEdgeCollect2[i].size() > 0)
                scratch.vertexSets2[i].push_back(genDcel.halfedges[genDcel.halfedges[scratch.boundEdgeCollect2[i][scratch.boundEdgeCollect2[i].size() - 1]].next].vertex);

            std::reverse(scratch.vertexSets2[i].begin(), scratch.vertexSets2[i].end());
        }
    }

    void build_vertex_matches(SimplifyScratch& scratch)
    {
        scratch.vertexMatches.clear();
        for (int i = 0; i < scratch.maxOrigHE + 1; i++) {
            log_progress("vertex match build", i, scratch.maxOrigHE + 1);
            std::vector<EVector3> PointSet1(scratch.vertexSets1[i].size());
            std::vector<EVector3> PointSet2(scratch.vertexSets2[i].size());
            for (int j = 0; j < PointSet1.size(); j++)
                PointSet1[j] = genDcel.vertices[scratch.vertexSets1[i][j]].data.eCoords;

            for (int j = 0; j < PointSet2.size(); j++)
                PointSet2[j] = genDcel.vertices[scratch.vertexSets2[i][j]].data.eCoords;

            std::vector<std::pair<int, int>> CurrMatches;
            if ((!PointSet1.empty()) && (!PointSet2.empty()))
                CurrMatches = FindVertexMatch(mData.verbose, PointSet1, PointSet2);

            for (int j = 0; j < CurrMatches.size(); j++) {
                CurrMatches[j].first = scratch.vertexSets1[i][CurrMatches[j].first];
                CurrMatches[j].second = scratch.vertexSets2[i][CurrMatches[j].second];
            }

            scratch.vertexMatches.insert(scratch.vertexMatches.end(), CurrMatches.begin(), CurrMatches.end());
        }
    }

    double scan_vertex_match_distance(const SimplifyScratch& scratch) const
    {
        double MaxDist = -327670000.0;
        for (int i = 0; i < scratch.vertexMatches.size(); i++)
            MaxDist = std::max(
                MaxDist,
                (genDcel.vertices[scratch.vertexMatches[i].first].data.coords -
                 genDcel.vertices[scratch.vertexMatches[i].second].data.coords)
                    .squaredNorm());

        if (mData.verbose)
            std::cout << "[Directional::NFunctionMesher::simplify_mesh()]: "
                      << "Max matching distance: " << MaxDist << std::endl;

        return MaxDist;
    }

    int compute_vertex_representatives(const SimplifyScratch& scratch)
    {
        TransVertices.resize(genDcel.vertices.size());
        return connectedComponents(scratch.vertexMatches, TransVertices);
    }

    void rebuild_vertex_table(const int numNewVertices)
    {
        std::vector<bool> transClaimed(numNewVertices);
        for (int i = 0; i < numNewVertices; i++)
            transClaimed[i] = false;

        std::vector<FunctionDCEL::Vertex> NewVertices(numNewVertices);
        for (int i = 0; i < genDcel.vertices.size(); i++) {
            log_progress("vertex representative rebuild", i, static_cast<int>(genDcel.vertices.size()));
            if (!genDcel.vertices[i].valid)
                continue;
            FunctionDCEL::Vertex NewVertex = genDcel.vertices[i];
            NewVertex.ID = TransVertices[i];
            transClaimed[TransVertices[i]] = true;
            NewVertices[TransVertices[i]] = NewVertex;
        }

        for (int i = 0; i < numNewVertices; i++)
            if (!transClaimed[i])
                NewVertices[i].valid = false;

        genDcel.vertices = NewVertices;
    }

    void remap_halfedge_vertices(std::vector<int>& preRemapOrigin, std::vector<int>& preRemapTarget)
    {
        for (int i = 0; i < genDcel.halfedges.size(); i++) {
            log_progress("halfedge vertex remap", i, static_cast<int>(genDcel.halfedges.size()));
            if (!genDcel.halfedges[i].valid)
                continue;
            preRemapOrigin[i] = genDcel.halfedges[i].vertex;
            if (genDcel.halfedges[i].next >= 0)
                preRemapTarget[i] = genDcel.halfedges[genDcel.halfedges[i].next].vertex;
            genDcel.halfedges[i].vertex = TransVertices[genDcel.halfedges[i].vertex];
            genDcel.vertices[genDcel.halfedges[i].vertex].halfedge = i;
        }
    }

    void prune_remap_created_degenerates(const std::vector<int>& preRemapOrigin,
                                         const std::vector<int>& preRemapTarget)
    {
        int prunedCount = 0;
        int detailedLogs = 0;
        for (int i = 0; i < genDcel.halfedges.size(); i++) {
            if (!genDcel.halfedges[i].valid)
                continue;
            const int next = genDcel.halfedges[i].next;
            if (next < 0 || !genDcel.halfedges[next].valid)
                continue;
            if (genDcel.halfedges[i].vertex != genDcel.halfedges[next].vertex)
                continue;

            if (mData.verbose && detailedLogs < 8) {
                std::cout << "[Directional::NFunctionMesher::simplify_mesh()]: pruning remap-created degenerate halfedge "
                          << i
                          << " origHalfedge=" << genDcel.halfedges[i].data.origHalfedge
                          << " face=" << genDcel.halfedges[i].face
                          << " edge=" << genDcel.halfedges[i].edge
                          << " twin=" << genDcel.halfedges[i].twin
                          << " before=(" << preRemapOrigin[i] << " -> " << preRemapTarget[i] << ")"
                          << " after=(" << genDcel.halfedges[i].vertex << " -> " << genDcel.halfedges[next].vertex << ")"
                          << " reps=("
                          << (preRemapOrigin[i] >= 0 ? TransVertices[preRemapOrigin[i]] : -1) << ", "
                          << (preRemapTarget[i] >= 0 ? TransVertices[preRemapTarget[i]] : -1) << ")"
                          << std::endl;
                detailedLogs++;
            }

            const int twin = genDcel.halfedges[i].twin;
            if (twin >= 0)
                genDcel.halfedges[twin].twin = -1;
            if (genDcel.halfedges[i].edge >= 0)
                genDcel.edges[genDcel.halfedges[i].edge].valid = false;
            genDcel.halfedges[i].twin = -1;
            genDcel.halfedges[i].valid = false;
            prunedCount++;
        }

        if (mData.verbose)
            std::cout << "[Directional::NFunctionMesher::simplify_mesh()]: pruned remap-created degenerate halfedges: "
                      << prunedCount << std::endl;

        int invalidatedVertices = 0;
        for (int i = 0; i < genDcel.vertices.size(); i++)
            genDcel.vertices[i].halfedge = -1;
        for (int i = 0; i < genDcel.halfedges.size(); i++) {
            if (!genDcel.halfedges[i].valid)
                continue;
            const int vertex = genDcel.halfedges[i].vertex;
            if (vertex >= 0 && genDcel.vertices[vertex].valid && genDcel.vertices[vertex].halfedge < 0)
                genDcel.vertices[vertex].halfedge = i;
        }
        for (int i = 0; i < genDcel.vertices.size(); i++) {
            if (!genDcel.vertices[i].valid)
                continue;
            if (genDcel.vertices[i].halfedge >= 0)
                continue;
            genDcel.vertices[i].valid = false;
            invalidatedVertices++;
        }
        if (mData.verbose && invalidatedVertices > 0)
            std::cout << "[Directional::NFunctionMesher::simplify_mesh()]: invalidated vertices without valid halfedges after remap prune: "
                      << invalidatedVertices << std::endl;
    }

    void retwin_halfedges()
    {
        std::set<FunctionDCEL::TwinFinder> Twinning;
        for (int i = 0; i < genDcel.halfedges.size(); i++) {
            log_progress("halfedge twinning", i, static_cast<int>(genDcel.halfedges.size()));
            if ((genDcel.halfedges[i].twin >= 0) || (!genDcel.halfedges[i].valid))
                continue;

            std::set<FunctionDCEL::TwinFinder>::iterator Twinit =
                Twinning.find(FunctionDCEL::TwinFinder(
                    0,
                    genDcel.halfedges[genDcel.halfedges[i].next].vertex,
                    genDcel.halfedges[i].vertex));
            if (Twinit != Twinning.end()) {
                if ((genDcel.halfedges[Twinit->index].twin != -1) && (mData.verbose))
                    std::cout << "warning: halfedge " << Twinit->index
                              << " is already twinned to halfedge "
                              << genDcel.halfedges[Twinit->index].twin << std::endl;
                if ((genDcel.halfedges[i].twin != -1) && (mData.verbose))
                    std::cout << "warning: halfedge " << i
                              << " is already twinned to halfedge "
                              << genDcel.halfedges[Twinit->index].twin << std::endl;
                genDcel.halfedges[Twinit->index].twin = i;
                genDcel.halfedges[i].twin = Twinit->index;

                genDcel.edges[genDcel.halfedges[Twinit->index].edge].valid = false;
                genDcel.halfedges[Twinit->index].edge = genDcel.halfedges[i].edge;

                if (genDcel.halfedges[i].data.isFunction) {
                    genDcel.halfedges[Twinit->index].data.isFunction = true;
                } else if (genDcel.halfedges[Twinit->index].data.isFunction) {
                    genDcel.halfedges[i].data.isFunction = true;
                }
                Twinning.erase(*Twinit);
            } else {
                Twinning.insert(FunctionDCEL::TwinFinder(
                    i,
                    genDcel.halfedges[i].vertex,
                    genDcel.halfedges[genDcel.halfedges[i].next].vertex));
            }
        }
    }

    void classify_triangle_regions(SimplifyScratch& scratch)
    {
        scratch.isPureTriangle.assign(genDcel.vertices.size(), true);
        scratch.isBoundary.assign(genDcel.vertices.size(), false);
        for (int i = 0; i < genDcel.vertices.size(); i++) {
            log_progress("triangle component init", i, static_cast<int>(genDcel.vertices.size()));
        }
        for (int i = 0; i < genDcel.halfedges.size(); i++) {
            log_progress("triangle component classify", i, static_cast<int>(genDcel.halfedges.size()));
            if ((genDcel.halfedges[i].data.isFunction) && (genDcel.halfedges[i].valid)) {
                scratch.isPureTriangle[genDcel.halfedges[i].vertex] =
                    scratch.isPureTriangle[genDcel.halfedges[genDcel.halfedges[i].next].vertex] = false;
            }
            if (genDcel.halfedges[i].twin == -1) {
                scratch.isBoundary[genDcel.halfedges[i].vertex] = true;
                scratch.isPureTriangle[genDcel.halfedges[i].vertex] = false;
            }
        }

        scratch.isEar.assign(genDcel.vertices.size(), false);
        for (int i = 0; i < genDcel.vertices.size(); i++) {
            scratch.isEar[i] =
                (genDcel.halfedges[genDcel.vertices[i].halfedge].twin == -1) &&
                (genDcel.halfedges[genDcel.halfedges[genDcel.vertices[i].halfedge].prev].twin == -1);
            if (scratch.isEar[i])
                scratch.isPureTriangle[i] = false;
        }
    }

    void realign_hex_halfedges(const SimplifyScratch& scratch)
    {
        for (int i = 0; i < genDcel.vertices.size(); i++) {
            log_progress("hex halfedge realignment", i, static_cast<int>(genDcel.vertices.size()));
            if ((scratch.isPureTriangle[i]) || (!genDcel.vertices[i].valid))
                continue;

            std::vector<int> hexHEorder;
            int hebegin = genDcel.vertices[i].halfedge;
            if (scratch.isBoundary[i]) {
                while (genDcel.halfedges[genDcel.halfedges[hebegin].prev].twin != -1)
                    hebegin = genDcel.halfedges[genDcel.halfedges[hebegin].prev].twin;
            }

            int heiterate = hebegin;
            do {
                if ((genDcel.halfedges[heiterate].data.isFunction) ||
                    (genDcel.halfedges[heiterate].twin == -1))
                    hexHEorder.push_back(heiterate);
                if (genDcel.halfedges[heiterate].twin == -1)
                    break;
                heiterate = genDcel.halfedges[genDcel.halfedges[heiterate].twin].next;
            } while (heiterate != hebegin);

            for (int j = 0; j < hexHEorder.size(); j++) {
                if ((scratch.isBoundary[i]) && (j == hexHEorder.size() - 1))
                    continue;
                genDcel.halfedges[hexHEorder[(j + 1) % hexHEorder.size()]].prev =
                    genDcel.halfedges[hexHEorder[j]].twin;
                genDcel.halfedges[genDcel.halfedges[hexHEorder[j]].twin].next =
                    hexHEorder[(j + 1) % hexHEorder.size()];
                genDcel.vertices[genDcel.halfedges[hexHEorder[j]].vertex].halfedge = hexHEorder[j];
            }

            if (scratch.isBoundary[i]) {
                genDcel.halfedges[hexHEorder[0]].prev = genDcel.halfedges[hebegin].prev;
                genDcel.halfedges[genDcel.halfedges[hebegin].prev].next = hexHEorder[0];
                genDcel.vertices[genDcel.halfedges[hexHEorder[0]].vertex].halfedge = hexHEorder[0];
            }
        }
    }

    void invalidate_triangle_regions(const SimplifyScratch& scratch)
    {
        for (int i = 0; i < genDcel.vertices.size(); i++)
            if (scratch.isPureTriangle[i])
                genDcel.vertices[i].valid = false;

        for (int i = 0; i < genDcel.halfedges.size(); i++)
            if ((!genDcel.halfedges[i].data.isFunction) && (genDcel.halfedges[i].twin != -1))
                genDcel.halfedges[i].valid = genDcel.edges[genDcel.halfedges[i].edge].valid = false;
    }

    bool realign_faces()
    {
        Eigen::VectorXi visitedHE = Eigen::VectorXi::Zero(genDcel.halfedges.size());
        Eigen::VectorXi usedFace = Eigen::VectorXi::Zero(genDcel.faces.size());
        for (int i = 0; i < genDcel.halfedges.size(); i++) {
            log_progress("face realignment", i, static_cast<int>(genDcel.halfedges.size()));
            if ((!genDcel.halfedges[i].valid) || (visitedHE[i] != 0))
                continue;

            const int currFace = genDcel.halfedges[i].face;
            genDcel.faces[currFace].halfedge = i;
            usedFace[currFace] = 1;
            const int hebegin = i;
            int heiterate = hebegin;
            int infinityCounter = 0;
            do {
                infinityCounter++;
                if (infinityCounter > genDcel.halfedges.size()) {
                    std::cout << "[Directional::NFunctionMesher::simplify_mesh()]: "
                              << "Infinity loop in realigning faces on halfedge " << i << std::endl;
                    return false;
                }
                genDcel.halfedges[heiterate].face = currFace;
                visitedHE[heiterate] = 1;
                heiterate = genDcel.halfedges[heiterate].next;
            } while (heiterate != hebegin);
        }

        for (int i = 0; i < genDcel.faces.size(); i++)
            if (!usedFace[i])
                genDcel.faces[i].valid = false;

        return true;
    }

    void prune_low_quality_faces_and_count_valence(SimplifyScratch& scratch)
    {
        scratch.valences.assign(genDcel.vertices.size(), 0);
        for (int i = 0; i < genDcel.halfedges.size(); i++) {
            log_progress("valence counting", i, static_cast<int>(genDcel.halfedges.size()));
            if (genDcel.halfedges[i].valid) {
                scratch.valences[genDcel.halfedges[i].vertex]++;
                if (genDcel.halfedges[i].twin < 0)
                    scratch.valences[genDcel.halfedges[genDcel.halfedges[i].next].vertex]++;
            }
        }

        int countThree = 0;
        for (int i = 0; i < genDcel.faces.size(); i++) {
            if (!genDcel.faces[i].valid)
                continue;
            countThree = 0;
            const int hebegin = genDcel.faces[i].halfedge;
            int heiterate = hebegin;
            do {
                if (scratch.valences[genDcel.halfedges[heiterate].vertex] > 2)
                    countThree++;
                heiterate = genDcel.halfedges[heiterate].next;
            } while (heiterate != hebegin);
            if (countThree < 3) {
                do {
                    genDcel.halfedges[heiterate].valid = false;

                    if (genDcel.halfedges[heiterate].twin != -1) {
                        if (!genDcel.halfedges[genDcel.halfedges[heiterate].twin].valid)
                            genDcel.edges[genDcel.halfedges[heiterate].edge].valid = false;
                        else
                            genDcel.edges[genDcel.halfedges[heiterate].edge].halfedge =
                                genDcel.halfedges[heiterate].twin;
                    } else {
                        genDcel.edges[genDcel.halfedges[heiterate].edge].valid = false;
                    }

                    if (genDcel.halfedges[heiterate].twin != -1)
                        genDcel.halfedges[genDcel.halfedges[heiterate].twin].twin = -1;
                    if ((genDcel.halfedges[heiterate].twin == -1) &&
                        (genDcel.halfedges[genDcel.halfedges[heiterate].prev].twin == -1))
                        genDcel.vertices[genDcel.halfedges[heiterate].vertex].valid = false;

                    heiterate = genDcel.halfedges[heiterate].next;
                } while (heiterate != hebegin);
                genDcel.faces[i].valid = false;
            }
        }
    }

    void refresh_vertex_halfedge_pointers()
    {
        for (int i = 0; i < genDcel.halfedges.size(); i++)
            if (genDcel.halfedges[i].valid)
                genDcel.vertices[genDcel.halfedges[i].vertex].halfedge = i;
    }

    int unify_low_valence_vertices(const SimplifyScratch& scratch)
    {
        for (int i = 0; i < scratch.valences.size(); i++)
            if ((genDcel.vertices[i].valid) && (scratch.valences[i] < 2))
                genDcel.vertices[i].valid = false;

        int unifyCount = 0;
        for (int i = 0; i < genDcel.vertices.size(); i++) {
            log_progress("low-valence edge unification", i, static_cast<int>(genDcel.vertices.size()));
            if ((genDcel.vertices[i].valid) && (scratch.valences[i] <= 2) && (!scratch.isEar[i])) {
                genDcel.unify_edges(genDcel.vertices[i].halfedge);
                unifyCount++;
            }
        }

        return unifyCount;
    }

    bool finalize_clean_mesh()
    {
        genDcel.clean_mesh();
        return genDcel.check_consistency(mData.verbose, true, true, true);
    }
    
    bool simplify_mesh(){
        //unifying vertices which are similar
        
        using namespace std;
        using namespace Eigen;
        using Clock = std::chrono::high_resolution_clock;

        SimplifyScratch scratch;

        const auto simplifyStart = Clock::now();
        auto phaseStart = simplifyStart;
        const auto logPhase = [&](const char* label) {
            if (!mData.verbose)
                return;
            const auto now = Clock::now();
            const auto phaseSeconds =
                std::chrono::duration_cast<std::chrono::microseconds>(now - phaseStart).count() / 1e+6;
            const auto totalSeconds =
                std::chrono::duration_cast<std::chrono::microseconds>(now - simplifyStart).count() / 1e+6;
            std::cout << "[Directional::NFunctionMesher::simplify_mesh()]: " << label
                      << " completed in " << phaseSeconds
                      << " s (total " << totalSeconds << " s)" << std::endl;
            phaseStart = now;
        };
        const auto shouldLogProgress = [&](int index, int total) {
            if (!mData.verbose || total <= 0)
                return false;
            if (index == 0 || index + 1 == total)
                return true;
            const int step = std::max(1, total / 10);
            return ((index + 1) % step) == 0;
        };
        const auto logProgress = [&](const char* label, int index, int total) {
            if (!shouldLogProgress(index, total))
                return;
            std::cout << "[Directional::NFunctionMesher::simplify_mesh()]: " << label << ": "
                      << (index + 1) << "/" << total << std::endl;
        };
        
        if (!run_initial_consistency_check())
            return false;
        logPhase("Initial consistency check");
        
        scan_original_halfedge_range(scratch);
        logPhase("Original halfedge range scan");
        
        if (!visit_boundary_seeds(scratch))
            return false;
        logPhase("Boundary visitation sweep");
        
        collect_boundary_strips(scratch);
        logPhase("Boundary strip collection");
        
        build_boundary_vertex_sets(scratch);
        logPhase("Boundary vertex set build");
        
        build_vertex_matches(scratch);
        logPhase("Vertex match build");
        
        //finding connected components, and uniting every component into a random single vertex in it (it comes out the last mentioned)
        /*Graph MatchGraph;
         for (int i=0;i<vertices.size();i++)
         add_vertex(MatchGraph);
         for (int i=0;i<VertexMatches.size();i++)
         add_edge(VertexMatches[i].first, VertexMatches[i].second, MatchGraph);*/
        
        scan_vertex_match_distance(scratch);
        logPhase("Vertex match distance scan");
        
        int NumNewVertices = compute_vertex_representatives(scratch);
        logPhase("Connected components");
        
        if (!genDcel.check_consistency(mData.verbose, false, false, false))
            return false;
        logPhase("Post-components consistency check");
        
        rebuild_vertex_table(NumNewVertices);
        logPhase("Vertex representative rebuild");
        
        std::vector<int> preRemapOrigin(genDcel.halfedges.size(), -1);
        std::vector<int> preRemapTarget(genDcel.halfedges.size(), -1);
        remap_halfedge_vertices(preRemapOrigin, preRemapTarget);
        logPhase("Halfedge vertex remap");

        prune_remap_created_degenerates(preRemapOrigin, preRemapTarget);
        logPhase("Remap-created degenerate halfedge pruning");
        
        if (!genDcel.check_consistency(mData.verbose, true, false, false))
            return false;
        logPhase("Post-remap consistency check");
        
        retwin_halfedges();
        logPhase("Halfedge twinning");
        
        //check if there are any non-twinned edge which shouldn't be in a closed mesh
        /*if (verbose){
         for (int i=0;i<Halfedges.size();i++){
         if (Halfedges[i].twin==-1)
         std::cout<<"Halfedge "<<i<<" does not have a twin!"<<std::endl;
         }
         }*/
        
        
        if (!genDcel.check_consistency(mData.verbose, true, true, true))
            return false;
        logPhase("Post-twinning consistency check");
        
        classify_triangle_regions(scratch);
        logPhase("Triangle component classification");
        
        realign_hex_halfedges(scratch);
        logPhase("Hex halfedge realignment");
        
        invalidate_triangle_regions(scratch);
        logPhase("Triangle invalidation");
        
        if (!realign_faces())
            return false;
        logPhase("Face realignment");
        logPhase("Unused face invalidation");
        
        
        prune_low_quality_faces_and_count_valence(scratch);
        logPhase("Valence counting and ear pruning");
        
        //need to realign all vertices pointing
        refresh_vertex_halfedge_pointers();
        logPhase("Vertex halfedge pointer refresh");
        
        
        if (!genDcel.check_consistency(mData.verbose, true, true, true))
            return false;
        logPhase("Post-pruning consistency check");
        
        int unifyCount = unify_low_valence_vertices(scratch);
        if (mData.verbose)
            std::cout << "[Directional::NFunctionMesher::simplify_mesh()]: Low-valence edge unification finished after "
                      << unifyCount << " operations" << std::endl;
        logPhase("Low-valence edge unification");
        
        if (!genDcel.check_consistency(mData.verbose, true, true, true))
            return false;
        logPhase("Post-unification consistency check");
        
        //remove non-valid components
        if (!finalize_clean_mesh())
            return false;
        logPhase("DCEL clean_mesh");
        logPhase("Final consistency check");
        
        return true;
        
    }
    
    void RemoveDegree2Faces();
    
    /*void Allocate(int NumofVertices, int NumofFaces, int NumofHEdges)
     {
     Vertices.resize(NumofVertices);
     faces.resize(NumofFaces);
     Halfedges.resize(NumofHEdges);
     }*/
    
    /*void init(const TriMesh& origMesh,
     const Eigen::MatrixXd& cutV,
     const Eigen::MatrixXi& cutF,
     const Eigen::VectorXd& vertexNFunction,
     const int N,
     const Eigen::SparseMatrix<double>& vertexToCornerMat,
     const Eigen::SparseMatrix<int>& exactVertexToCornerMat,
     const Eigen::VectorXi& integerVars,
     const unsigned long resolution=1e7)*/
    void init(const unsigned long resolution=1e7){
        
        using namespace std;
        using namespace Eigen;
        
        //computing exact rational corner values by quantizing the free variables d and then manually performing the sparse matrix multiplication
        vector<ENumber> exactVertexNFunction(mData.vertexNFunction.size());
        double tol = 1.0/(double)resolution;
        for (int i=0;i<mData.vertexNFunction.size();i++){
            //exactVertexNFunction[i]=ENumber((long long)round((long double)(mData.vertexNFunction(i)*resolution)),(long long)resolution);
            exactVertexNFunction[i]=ENumber(mData.vertexNFunction(i),tol);
            
            /*if (abs(exactVertexNFunction[i].to_double() - mData.vertexNFunction(i))>2.0/(double)resolution) {
             cout << "exactVertexNFunction[i].to_double(): " << exactVertexNFunction[i].to_double() << endl;
             cout << "vertexNFunction(i): " << mData.vertexNFunction(i) << endl;
             cout << "(long double)(vertexNFunction(i)*resolution): " << (long double)(mData.vertexNFunction(i) * resolution) << endl;
             }*/
        }
        
        for (int i=0;i<mData.integerVars.size();i++){
            exactVertexNFunction[mData.integerVars(i)]=ENumber((long)round(mData.vertexNFunction(mData.integerVars(i))));
            //cout<<"rounding diff of integer var "<<mData.integerVars(i)<<" is "<<exactVertexNFunction[mData.integerVars(i)].to_double()-mData.vertexNFunction(mData.integerVars(i))<<endl;
        }
        
        VectorXd cutNFunctionVec = mData.orig2CutMat*mData.vertexNFunction;
        vector<ENumber> exactCutNFunctionVec;
        exactSparseMult(mData.exactOrig2CutMat, exactVertexNFunction,exactCutNFunctionVec);
        
        //sanity check - comparing exact to double
        double maxError2 = -32767000.0;
        for (int i=0;i<exactCutNFunctionVec.size();i++){
            double fromExact = exactCutNFunctionVec[i].to_double();
            if (abs(fromExact-cutNFunctionVec[i])>maxError2){
                maxError2 =abs(fromExact-cutNFunctionVec[i]);
                //cout<<"i, fromExact, cutNFunctionVec[i]: "<<i<<","<<fromExact<<","<<cutNFunctionVec[i]<<endl;
            }
        }
        
        if (mData.verbose)
            cout<<"double from exact in halfedges maxError2: "<<maxError2<<endl;
        
        exactNFunction.resize(origMesh.F.size());
        NFunction.resize(origMesh.F.size(), 3*mData.N);
        
        for (int i=0;i<origMesh.F.rows();i++){
            exactNFunction[i].resize(3*mData.N);
            for (int j=0;j<3;j++){
                //Halfedges[FH(i,j)].exactNFunction.resize(N);
                NFunction.block(i, mData.N*j, 1, mData.N) = cutNFunctionVec.segment(mData.N*mData.cutF(i,j), mData.N).transpose();
                for (int k=0;k<mData.N;k++)
                    exactNFunction[i][j*mData.N+k] = exactCutNFunctionVec[mData.N*mData.cutF(i,j)+k];
            }
        }
        
    }
    
    
    //corner angles is per vertex in each F
    void to_polygonal(Eigen::MatrixXd& generatedV,
                      Eigen::VectorXi& generatedD,
                      Eigen::MatrixXi& generatedF){
        generatedV.resize(genDcel.vertices.size(),3);
        
        generatedD.resize(genDcel.faces.size());
        
        for (int i=0;i<genDcel.vertices.size();i++)
            generatedV.row(i)=genDcel.vertices[i].data.coords;
        
        
        for (int i=0;i<genDcel.faces.size();i++){
            int hebegin = genDcel.faces[i].halfedge;
            //reseting to first vertex
            int vCount=0;
            int heiterate=hebegin;
            do{
                vCount++;
                heiterate=genDcel.halfedges[heiterate].next;
            }while (heiterate!=hebegin);
            generatedD(i)=vCount;
        }
        
        generatedF.resize(genDcel.faces.size(),generatedD.maxCoeff());
        for (int i=0;i<genDcel.faces.size();i++){
            int hebegin = genDcel.faces[i].halfedge;
            int vCount=0;
            int heiterate=hebegin;
            do{
                generatedF(i,vCount++)=genDcel.halfedges[heiterate].vertex;
                heiterate=genDcel.halfedges[heiterate].next;
            }while (heiterate!=hebegin);
            
        }
        
        
    }
    
    NFunctionMesher(const TriMesh& _origMesh, const MesherData& _mData ):origMesh(_origMesh), mData(_mData){}
    ~NFunctionMesher(){}
    
private:
    void arrange_on_triangle(const std::vector<EVector2>& triangle,
                             const std::vector<std::pair<EVector2, EVector2>>& lines,
                             const Eigen::VectorXi& lineData,
                             std::vector<EVector2>& V,
                             FunctionDCEL & dcel,
                             Eigen::VectorXi& dataH);
    
    void segment_arrangement(const std::vector<std::pair<EVector2, EVector2>>& segments,
                             const std::vector<int>& data,
                             std::vector<EVector2>& V,
                             FunctionDCEL& dcel,
                             Eigen::VectorXi& dataH);
    
};

}

#endif //DIRECTIONAL_N_FUNCTION_MESHER
