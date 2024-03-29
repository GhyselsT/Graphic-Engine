//
// Created by thomg on 16/03/2023.
//

#include "Functies.h"
#include "Figure.h"
#include "Face.h"

#include "cmath"
#include <stack>

#include "iostream"

#define M_PI 3.14159265358979323846264338327950288419716939937510

using namespace std;


Figure createKubus(){
    Figure cube;
    //Points emplacen
    cube.points.emplace_back(Vector3D::point(1,-1,-1));
    cube.points.emplace_back(Vector3D::point(-1,1,-1));
    cube.points.emplace_back(Vector3D::point(1,1,1));
    cube.points.emplace_back(Vector3D::point(-1,-1,1));
    cube.points.emplace_back(Vector3D::point(1,1,-1));
    cube.points.emplace_back(Vector3D::point(-1,-1,-1));
    cube.points.emplace_back(Vector3D::point(1,-1,1));
    cube.points.emplace_back(Vector3D::point(-1,1,1));

    //Faces emplacen
    cube.faces.emplace_back(Face({0, 4, 2, 6}));
    cube.faces.emplace_back(Face({4, 1, 7, 2}));
    cube.faces.emplace_back(Face({1, 5, 3, 7}));
    cube.faces.emplace_back(Face({5, 0, 6, 3}));
    cube.faces.emplace_back(Face({6, 2, 7, 3}));
    cube.faces.emplace_back(Face({0, 5, 1, 4}));

    return cube;
}

Figure createTetrahedron(){
    Figure t;
    //points emplace
    t.points.emplace_back(Vector3D::point(1,-1,-1));
    t.points.emplace_back(Vector3D::point(-1,1,-1));
    t.points.emplace_back(Vector3D::point(1,1,1));
    t.points.emplace_back(Vector3D::point(-1,-1,1));

    //faces emplace
    t.faces.emplace_back(Face({0, 1, 2}));
    t.faces.emplace_back(Face({1, 3, 2}));
    t.faces.emplace_back(Face({0, 3, 1}));
    t.faces.emplace_back(Face({0, 2, 3}));

    return t;
}

Figure createOctahedron(){
    Figure o;
    //points emplace
    o.points.emplace_back(Vector3D::point(1,0,0));
    o.points.emplace_back(Vector3D::point(0,1,0));
    o.points.emplace_back(Vector3D::point(-1,0,0));
    o.points.emplace_back(Vector3D::point(0,-1,0));
    o.points.emplace_back(Vector3D::point(0,0,-1));
    o.points.emplace_back(Vector3D::point(0,0,1));

    //Faces emplace
    o.faces.emplace_back(Face({0,1,5}));
    o.faces.emplace_back(Face({1,2,5}));
    o.faces.emplace_back(Face({2,3,5}));
    o.faces.emplace_back(Face({3,0,5}));
    o.faces.emplace_back(Face({1,0,4}));
    o.faces.emplace_back(Face({2,1,4}));
    o.faces.emplace_back(Face({3,2,4}));
    o.faces.emplace_back(Face({0,3,4}));

    return o;
}

Figure createIcosahedron(){
    Figure i;
    //points emplace
    for (int teller = 1; teller <=12; ++teller) {
        if (teller == 1){
            i.points.emplace_back(Vector3D::point(0, 0, sqrt(5)/2));
        }
        else if (teller == 2 or teller == 3 or teller == 4 or teller == 5 or teller == 6){
            double x = cos((teller - 2) * 2 * M_PI/5);
            double y = sin((teller - 2) * 2 * M_PI/5);
            double z = 0.5;
            i.points.emplace_back(Vector3D::point(x, y, z));
        }
        else if (teller == 7 or teller == 8 or teller == 9 or teller == 10 or teller == 11){
            double x = cos(M_PI/5 + (teller - 7) * 2 * M_PI/5);
            double y = sin(M_PI/5 + (teller - 7) * 2 * M_PI/5);
            double z = -0.5;
            i.points.emplace_back(Vector3D::point(x, y, z));
        }
        else if (teller == 12){
            i.points.emplace_back(Vector3D::point(0, 0, -sqrt(5)/2));
        }
    }
    //Faces emplace
    i.faces.emplace_back(Face({0,1,2}));
    i.faces.emplace_back(Face({0,2,3}));
    i.faces.emplace_back(Face({0,3,4}));
    i.faces.emplace_back(Face({0,4,5}));
    i.faces.emplace_back(Face({0,5,1}));
    i.faces.emplace_back(Face({1,6,2}));
    i.faces.emplace_back(Face({2,6,7}));
    i.faces.emplace_back(Face({2,7,3}));
    i.faces.emplace_back(Face({3,7,8}));
    i.faces.emplace_back(Face({3,8,4}));
    i.faces.emplace_back(Face({4,8,9}));
    i.faces.emplace_back(Face({4,9,5}));
    i.faces.emplace_back(Face({5,9,10}));
    i.faces.emplace_back(Face({5,10,1}));
    i.faces.emplace_back(Face({1,10,6}));
    i.faces.emplace_back(Face({11,7,6}));
    i.faces.emplace_back(Face({11,8,7}));
    i.faces.emplace_back(Face({11,9,8}));
    i.faces.emplace_back(Face({11,10,9}));
    i.faces.emplace_back(Face({11,6,10}));

    return i;
}
Vector3D GetMid(vector<Vector3D> points,const int corners){
    double x = 0.0, y = 0.0 , z = 0.0;
    for (int i = 0; i < corners; ++i) {
        x += points[i].x;
        y += points[i].y;
        z += points[i].z;
    }
    x/=corners, y/=corners, z/=corners;
    return Vector3D::point(x,y,z);
}

Figure createDodecahedron(){
    Figure d;
    //points emplacen
    Figure ico = createIcosahedron();
    for(const auto& face:ico.faces ){
        vector<Vector3D> p;
        for(auto item : face.point_indexes){
            p.emplace_back(ico.points[item]);
        }
        d.points.emplace_back(GetMid(p,3));
    }

    //Faces emplacen
    d.faces.emplace_back(Face({0,1,2,3,4}));
    d.faces.emplace_back(Face({0,5,6,7,1}));
    d.faces.emplace_back(Face({1,7,8,9,2}));
    d.faces.emplace_back(Face({2,9,10,11,3}));
    d.faces.emplace_back(Face({3,11,12,13,4}));
    d.faces.emplace_back(Face({4,13,14,5,0}));
    d.faces.emplace_back(Face({19,18,17,16,15}));
    d.faces.emplace_back(Face({19,14,13,12,18}));
    d.faces.emplace_back(Face({18,12,11,10,17}));
    d.faces.emplace_back(Face({17,10,9,8,16}));
    d.faces.emplace_back(Face({16,8,7,6,15}));
    d.faces.emplace_back(Face({15,6,5,14,19}));

    return d;
}

Figure createSphere(double radius, const int n){
    Figure sphere = createIcosahedron();
    for (int i = 0; i < n; ++i) {
        vector<Face> newfaces;
        for (auto f: sphere.faces) {
            Vector3D A, B, C, D, E, F;
            A = sphere.points[f.point_indexes[0]];
            B = sphere.points[f.point_indexes[1]];
            C = sphere.points[f.point_indexes[2]];
            D = Vector3D::point((A.x + B.x) / 2,
                                (A.y + B.y) / 2,
                                (A.z + B.z) / 2);

            E = Vector3D::point((A.x + C.x) / 2,
                                (A.y + C.y) / 2,
                                (A.z + C.z) / 2);

            F = Vector3D::point((B.x + C.x) / 2,
                                (B.y + C.y) / 2,
                                (B.z + C.z) / 2);

            sphere.points.emplace_back(D);
            sphere.points.emplace_back(E);
            sphere.points.emplace_back(F);

            int aidx = f.point_indexes[0];
            int bidx = f.point_indexes[1];
            int cidx = f.point_indexes[2];
            int didx = sphere.points.size() - 3;
            int eidx = sphere.points.size() - 2;
            int fidx = sphere.points.size() - 1;

            //in vector zetten
            newfaces.emplace_back(Face({aidx, didx, eidx}));
            newfaces.emplace_back(Face({bidx, fidx, didx}));
            newfaces.emplace_back(Face({cidx, eidx, fidx}));
            newfaces.emplace_back(Face({didx, fidx, eidx}));
        }
        sphere.faces = newfaces;
    }
    //TODO wrm moet dit niet.
//    for (auto &p: sphere.points) {
//        radius = sqrt(pow(p.x, 2) + pow(p.y, 2) + pow(p.z, 2));
//        p = Vector3D::point(p.x / radius, p.y / radius, p.z / radius);
//    }
    for (auto &p: sphere.points) {
        p = Vector3D::normalise(p);
    }

    return sphere;
}

Figure createCone(const int n,const double h){
    Figure cone;

    for (int i = 0; i < n; ++i){
        //points emplacen
        cone.points.emplace_back(Vector3D::point(cos(2 * i * M_PI / n),sin(2 * i * M_PI / n),0));
        //faces emplacen
        cone.faces.emplace_back((Face({i, (i+1)%n, n})));
    }
    //top emplacen
    cone.points.emplace_back(Vector3D::point(0,0,h));

    return cone;
}


Figure createCylinder(const int n, const double h){
    Figure c;
    for (int i = 0; i < n; ++i) {
        //points
        //bottom
        c.points.emplace_back(Vector3D::point(cos(2*i*M_PI/n), sin(2*i*M_PI/n), 0));
        //top
        c.points.emplace_back(Vector3D::point(cos(2*i*M_PI/n), sin(2*i*M_PI/n), h));

    }
    vector<int>bv,ov;
    for (int i = 0; i < 2*n; i+=2) {
        bv.push_back(i);
        ov.push_back((2*i) -(i+1));
    }
    c.faces.emplace_back(bv);
    c.faces.emplace_back(ov);
    for (int i = 0; i < 2*n; i+=2) {
        c.faces.emplace_back(Face({i,(i+1)%(2*n),(i+3)%(2*n),(i+2)%(2*n)}));
    }
    return c;
}

Figure createTorus(const double r,const double R,const int n, const int m) {
    Figure torus;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //points
            double u = (2 * i * M_PI) / n;
            double v = (2 * j * M_PI) / m;

            Vector3D point = Vector3D::point((R + r * cos(v)) * cos(u), (R + r * cos(v)) * sin(u), r * sin(v));
            torus.points.push_back(point);

            //faces
            Face face = Face({i * n + j, ((i + 1) % n) * n + j, ((i + 1) % n) * n + (j + 1) % m, i * n + (j + 1) % n});
            torus.faces.push_back(face);
        }
    }
    return torus;
}

Figure draw3Dlsystem(const LParser::LSystem3D &sys){
    Figure lsys;

    string initiator = sys.get_initiator();
    double iterations = sys.get_nr_iterations();
    string draw;
    if (iterations == 0){
        draw = initiator;
    }
    else{
        for (int i = 0; i <iterations ; ++i) {
            draw="";
            for(char j : initiator){
                if (j =='+'){
                    draw.append("+");
                }else if(j =='-'){
                    draw.append("-");
                }else if (j == '(') {
                    draw.append("(");
                }else if (j == ')') {
                    draw.append(")");
                }else if (j == '/') {
                    draw.append("/");
                }else if (j == '\\') {
                    draw.append("\\");
                }else if (j == '&') {
                    draw.append("&");
                }else if (j == '|') {
                    draw.append("|");
                }else if (j == '^'){
                    draw.append("^");
                }
                else{
                    draw.append(sys.get_replacement(j));
                }
            }
            initiator = draw;
        }
    }
    //cout << draw;

    Vector3D currentpoint = Vector3D::point(0,0,0);
    Vector3D H = Vector3D::vector(1,0,0);
    Vector3D L = Vector3D::vector(0,1,0);
    Vector3D U = Vector3D::vector(0,0,1);

    Vector3D temp = Vector3D::vector(0,0,0);


    double angle = GradToRad(sys.get_angle());
    //stacks
    stack<Vector3D> points;
    stack<Vector3D> hoekH;
    stack<Vector3D> hoekL;
    stack<Vector3D> hoekU;

    lsys.points.emplace_back(currentpoint);
    int ctr = 1;
    Face face;

    for(char k : draw){
        if (k == '('){
            points.emplace(currentpoint);
            hoekH.emplace(H);
            hoekL.emplace(L);
            hoekU.emplace(U);
        }
        else if(k == ')'){
            currentpoint = points.top(); points.pop();
            lsys.points.emplace_back(currentpoint);
            ctr+=1;
            H = hoekH.top(); hoekH.pop();
            L = hoekL.top(); hoekL.pop();
            U = hoekU.top(); hoekU.pop();
        }
        else if(k == '+'){
            temp = H;
            H = temp*cos(angle) + L*sin(angle);
            L = -(temp*sin(angle)) + L*cos(angle);
        }
        else if(k == '-'){
            temp = H;
            H = temp*cos(-angle) + L*sin(-angle);
            L = -(temp*sin(-angle)) + L*cos(-angle);
        }
        else if(k =='^'){
            temp = H;
            H = temp*cos(angle) + U*sin(angle);
            U = -(temp*sin(angle)) + U*cos(angle);
        }
        else if(k == '&'){
            temp = H;
            H = temp*cos(-angle) + U*sin(-angle);
            U = -(temp*sin(-angle)) + U*cos(-angle);
        }
        else if(k =='\\'){
            temp = L;
            L = temp* cos(angle) - U* sin(angle);
            U = temp* sin(angle) + U* cos(angle);
        }
        else if(k == '/'){
            temp = L;
            L = temp* cos(-angle) - U* sin(-angle);
            U = temp* sin(-angle) + U* cos(-angle);
        }
        else if(k == '|'){
            H= -H;
            L= -L;
        }
        else{
            currentpoint+=H;
            lsys.points.emplace_back(currentpoint);
            //cout << lsys.points.back();
            if (sys.draw(k)){
                face.point_indexes = {ctr-1,ctr};
                lsys.faces.emplace_back(face);
            }
            ctr +=1;
        }
    }
    return lsys;
}
