#include<iostream>
using namespace std;

class shape
{
    public:
    shape(float _A = 0 , float _B = 0, float _C = 0 , float _density = 1)
    {
        A = _A;
        B = _B;
        C = _C;
        density = _density;
    }

    float EvalVolume()
    {
        _Volume = A*B*C;
        return  _Volume;
    }

    float EvalSurfaceArea()
    {
        _SurfaceArea =  2*(A*B + B*C + A*C);
        return _SurfaceArea;
    }

    float EvalMass()
    {
        _Mass = _Volume * density;
        return _Mass;
    }


    void SetX(float x)
    {
        A = x;
    }


     void SetY(float y)
    {
        B = y;
    }


     void SetZ(float z)
    {
        C = z;
    }

    private:
    float A, B, C,  _SurfaceArea ,_Volume,_Mass, density;
};


class sphere
{
    public:
    sphere(float _radius = 0 , float _density = 1)
    {
       radius =  _radius;
       density = _density;
    }

    float EvalVolume()
    {
        _volume = (4.0 / 3.0) * 3.14 * radius * radius * radius;
        return _volume;
    }

    float EvalSurfaceArea() 
    { 
        _SurfaceArea = 4 * 3.14 * radius * radius; 
        return _SurfaceArea;
    }

    float EvalMass()
    {
        _Mass = _volume * density;
        return _Mass;
    }

    void SetRadius(float _radius)
    {
        radius = _radius;   
    }

    private:
    float radius , _volume , _SurfaceArea ,  _Mass;
    float density;
} ;


class cylinder 
{
    public:
    cylinder (float _height = 0 , float _radius = 0 ,float _density = 1)
    {
        height = _height;
        radius = _radius;
        density = _density;
    }
    

    float EvalVolume ()
    {
           _volume = (3.14 * radius * radius * height);
           return _volume;
    }


    float EvalSurfaceArea ()
    {
        _SurfaceArea = (4.0 * 3.14 * radius) + (2.0 * 3.14 * radius * height);
        return _SurfaceArea;
    }


    float EvalMass()
    {
        _Mass = _volume * density;
        return _Mass;
    }

    private:
    float height , radius , density , _volume , _SurfaceArea ,  _Mass;
};