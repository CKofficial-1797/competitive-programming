#include <bits/stdc++.h>
#include <numeric>
using namespace std;

class Solution {
public:
    struct slope {
        int n, d;
        slope(int a=0, int b=1) {
            if (b < 0) a = -a, b = -b;
            int g = std::gcd(abs(a), abs(b));
            if (g == 0) { n = 0; d = 1; }
            else { n = a / g; d = b / g; }
        }
        bool operator==(const slope &o) const {
            return n == o.n && d == o.d;
        }
    };

    struct slopeHash {
        size_t operator()(const slope &s) const {
            size_t h1 = hash<long long>()(s.n);
            size_t h2 = hash<long long>()(s.d);
            
            return h1 ^ (h2 + 0x9e3779b97f4a7c15ULL + (h1<<6) + (h1>>2));
        }
    };

    struct pointXY {
        int x1, y1, x2, y2;
        pointXY(int a=0, int b=0, int c=0, int d=0) : x1(a), y1(b), x2(c), y2(d) {}
    };

    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<slope, vector<pointXY>, slopeHash> mpp;

        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                int dx = x2 - x1;
                int dy = y2 - y1;
                int g = std::gcd(abs(dx), abs(dy));
               
                slope s(dy == 0 && dx == 0 ? 0 : dy / (g==0?1:g), dx == 0 && dy == 0 ? 1 : dx / (g==0?1:g));
                mpp[s].emplace_back(x1, y1, x2, y2);
            }
        }

        int cnt = 0;
        for (auto &pr : mpp) {
            auto &vec = pr.second;
            int sz = vec.size();
            for (int i = 0; i < sz; ++i) {
                for (int j = i + 1; j < sz; ++j) {
                    auto &p1 = vec[i];
                    auto &p2 = vec[j];
                    if ((p1.x1 != p2.x1) && (p1.x2 != p2.x2) &&
                        (p1.y1 != p2.y1) && (p1.y2 != p2.y2) &&
                        (p1.x1 != p2.x2) && (p1.x2 != p2.x1) &&
                        (p1.y1 != p2.y2) && (p1.y2 != p2.y1)) {
                        
                        vector<pair<int,int>>endPoints= {{p1.x1,p1.y1},{p1.x2,p1.y2},{p2.x1,p2.y1},{p2.x2,p2.y2}};
                        long double cx =(p1.x1+p1.x2+p2.x1+p2.x2)/4.0L;
                        long double  cy = (p1.y1+p1.y2+p2.y1+p2.y2)/4.0L;
                        sort(endPoints.begin(),endPoints.end(),[cx,cy](const pair<int,int>&x, const pair<int,int>&y){
                            long double xx = atan2(x.second-cy ,x.first-cx);
                            long double yy = atan2(y.second-cy , y.first-cx);
                            return xx< yy;
                        });
                        pair<int, int >P0 =endPoints[0];
                        pair<int, int >P1 =endPoints[1];
                        pair<int, int >P2 =endPoints[2];
                        pair<int, int >P3 =endPoints[3];
                        //find vectors
                        //at P0
                        pair<int, int >P10 ={P1.first-P0.first ,P1.second-P0.second};
                        pair<int, int >P30 ={P3.first-P0.first ,P3.second-P0.second};
                        long long cross013 = P10.first*P30.second - P10.second*P30.first ;
                        bool pos =false ,neg =false;
                        if(cross013>0){
                            pos =true;
                        }else if(cross013==0){
                            continue;
                        }
                        else {
                            neg =true;
                        } ;

                        //at P1
                        pair<int, int >P01 ={P0.first-P1.first ,P0.second-P1.second};
                        pair<int, int >P21 ={P2.first-P1.first ,P2.second-P1.second};
                        long long cross102= P01.first*P21.second - P01.second*P21.first ;
                        
                        if(cross102>0){
                            if(neg)continue;

                        }else if(cross102==0){
                            continue;
                        }
                        else {
                           if(pos)continue;
                        } ;
                        //at P2
                        pair<int, int >P012 ={P1.first-P2.first ,P1.second-P2.second};
                        pair<int, int >P212 ={P3.first-P2.first ,P3.second-P2.second};
                        long long cross1022= P012.first*P21.second - P012.second*P21.first ;
                        
                        if(cross1022>0){
                            if(neg)continue;

                        }else if(cross1022==0){
                            continue;
                        }
                        else {
                           if(pos)continue;
                        } ;
                        //at P3
                        pair<int, int >P013 ={P0.first-P3.first ,P0.second-P3.second};
                        pair<int, int >P213 ={P2.first-P3.first ,P2.second-P3.second};
                        long long cross1023= P013.first*P21.second - P013.second*P21.first ;
                        
                        if(cross1023>0){
                            if(neg)continue;

                        }else if(cross1023==0){
                            continue;
                        }
                        else {
                           if(pos)continue;
                        } ;

                        //if reaches here then it is valid trapezoid 
                        cnt++;



                    }
                }
            }
        }
        return (int)cnt;
    }
};
