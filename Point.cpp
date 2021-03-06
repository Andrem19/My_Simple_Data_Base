//
// Created by 72555 on 9/19/2021.
//

#include <iostream>
#include "Point.h"


Point::Point(int x, int y, int z) {

    Temp ++ ;
    this->Id = Temp;
    this->Tm = time(NULL);
    this->x = x;
    this->y = y;
    this->z = z;
    this->prev_hash = get_last_hash();
    string toHash = to_string(x) + to_string(y) + to_string(z) + to_string(Tm) + to_string(Id) + prev_hash;
    hash<string> string_hash;
    size_t h = string_hash(toHash);
    this->curr_hash = h;

}
int Point::Temp = stoi(Point::get_last_id());

ostream& operator<<(ostream& os, const Point& point)
{
    os<<point.Id<<", "<<point.Tm<<", "<<point.x<<", "<<point.y<<", "<<point.z<<", "<<point.curr_hash<<", "<<point.prev_hash<<", ";
    return os;
}
istream& operator>>(istream& is, Point& point)
{
    is>>point.Id>>point.Tm>>point.x>>point.y>>point.z>>point.curr_hash>>point.prev_hash;
    return is;
}

Point::Point() {
auto Id = Tm = x = y = z = curr_hash = 0;
prev_hash = "0";
}

string Point::get_last_hash() {
    vector<string> vecHash;
    vecHash = get_vector();
    string lastHash = vecHash[vecHash.size()-2];
    cout<<"last Hash: "<<lastHash<<endl;
    return lastHash;
}

string Point::get_last_id() {
    vector<string> vecID;
    vecID = get_vector();
    string last_id = vecID[vecID.size()-7];
    cout<<"last id: "<<last_id<<endl;
    return last_id;
}

vector<string> Point::get_vector()
{
    ifstream file("simple_DB.csv");
    string segment;
    vector<string> vec;
    int i = 0;
    while(getline(file, segment))
    {
        vec.push_back(segment);
        i++;
    }
    vector<string> vec2;
    string s;
    for (int j = 0; j < vec.size(); ++j) {
        stringstream ssin(vec[j]);

        while(getline(ssin, s, ' '))
        {
            vec2.push_back(s);
        }
    }
    string t;
    for (int j = 0; j < vec2.size(); ++j) {
        stringstream ssin(vec2[j]);
        while(getline(ssin, t, ','))
        {
            vec2[j] = t;
        }
    }
    return vec2;
}


