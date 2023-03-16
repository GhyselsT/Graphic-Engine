//
// Created by thomg on 16/03/2023.
//

#define _USE_MATH_DEFINES
#include "Figure.h"
#include "Face.h"

#include "cmath"

#include "iostream"

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
    o.faces.emplace_back(Face({1,2,6}));
    o.faces.emplace_back(Face({2,3,6}));
    o.faces.emplace_back(Face({3,4,6}));
    o.faces.emplace_back(Face({4,1,6}));
    o.faces.emplace_back(Face({2,1,5}));
    o.faces.emplace_back(Face({3,2,5}));
    o.faces.emplace_back(Face({4,3,5}));
    o.faces.emplace_back(Face({1,4,5}));

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
            double x = cos((teller-2)*2*M_PI/5);
            double y = sin((teller-2)*2*M_PI/5);
            double z = 0.5;
            i.points.emplace_back(Vector3D::point(x, y, z));
        }
        else if (teller == 7 or teller == 8 or teller == 9 or teller == 10 or teller == 11){
            double x = cos(M_PI/5 + (teller-7)*2*M_PI/5);
            double y = sin(M_PI/5 + (teller-7)*2*M_PI/5);
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

