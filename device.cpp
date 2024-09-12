#include<iostream>
#include"shapes.h"
#include<vector>
using namespace std;


class Device
{
    private:
    vector<Device*>child_vec;
    vector<shape*>shape_vec;
    string DeviceName;

    public:
    Device()
    {
        DeviceName = "device1";
    }
    
    Device(string name)
    {   
        DeviceName = name;
    }

    void get_child (Device device)
    {
        child_vec.push_back(&device);
    }


     void get_shape (shape shape)
    {
        shape_vec.push_back(&shape);
    }


    float GetVolume()
    {
        float tmpVolume = 0;
        for(auto tmpshape : shape_vec)
        {
           tmpVolume = tmpVolume + tmpshape->EvalVolume();
        }
        for(auto tmpchild : child_vec)
        {
            tmpVolume = tmpVolume + tmpchild->GetVolume();
        }
        return tmpVolume;
    }

    float GetSurfaceArea()
    {
        float tmpSurfaceArea = 0;
        for(auto tmpshape : shape_vec)
        {
           tmpSurfaceArea = tmpSurfaceArea + (*tmpshape).EvalSurfaceArea();
        }
        for(auto tmpchild : child_vec)
        {
            tmpSurfaceArea = tmpSurfaceArea + tmpchild->GetSurfaceArea();
        }
        return tmpSurfaceArea;
    }

    float GetMass()
    {
        float tmpMass = 0;
        for(auto tmpshape : shape_vec)
        {
           tmpMass = tmpMass + (*tmpshape).EvalMass();
        }
        for(auto tmpchild : child_vec)
        {
            tmpMass = tmpMass + tmpchild->GetMass();
        }
        return tmpMass;
    }
    
};



int main()
{
    Device Laptop;
    Device CPU;
    Device RAM;
    Device MotherBoard;
    shape cube(2, 2, 2, 1);
    shape cubeCPU(2, 5, 3, 5);
    shape cubeRAM(1, 2, 3, 4);

    Laptop.get_child(CPU);
    Laptop.get_child(RAM);
    Laptop.get_child(MotherBoard);
    Laptop.get_shape(cube);
    Laptop.get_shape(cubeCPU);
    Laptop.get_shape(cubeRAM);
    cout << Laptop.GetVolume() << endl;
    cout << Laptop.GetSurfaceArea() << endl;
    cout << Laptop.GetMass() << endl;
}