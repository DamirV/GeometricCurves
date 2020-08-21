#pragma once
#include <iostream>

using namespace std;
class CurveEllipse : public CentralPoint {
private:
	float radiusX;
	float radiusY;

public:
	CurveEllipse() : CentralPoint() {
		radiusX = radiusY = 1;
	}

	CurveEllipse(vector<float> _center, float _radiusX, float _radiusY) : CentralPoint(_center) {
		radiusX = radiusY = 1;
		try {
			if (_radiusX < 0 || radiusY < 0) {
				throw 1;
			}
			radiusX = _radiusX;
			radiusY = _radiusY;
		}
		catch (int exeptionID) {
			cout << "Error " << exeptionID << " radius < 0" << endl;
		}
	}


	friend ostream& operator<< (ostream& out, const CurveEllipse& cEllipse) {

		return out << "Ellipse { \n"
			<< "    Center: (" << cEllipse.center[0] << ", " << cEllipse.center[1] << ", " << cEllipse.center[2] << ") \n"
			<< "    RadiusX: " << cEllipse.radiusX << "\n"
			<< "    RadiusY: " << cEllipse.radiusY << "\n"
			<< "}" << endl;
	}

	void Print() {
		cout << "Ellipse { \n"
			<< "    Center: (" << center[0] << ", " << center[1] << ", " << center[2] << ") \n"
			<< "    RadiusX: " << radiusX << "\n"
			<< "    RadiusY: " << radiusY << "\n"
			<< "}" << endl;
	}

	vector<float> GetPoint(float t) {
		float x = radiusX * cos(t) + center[0];
		float y = radiusY * sin(t) + center[1];
		float z = center[2];

		return { x, y, z };
	}

	vector<float> GetPointDerivative(float t) {
		float x = -radiusX * sin(t);
		float y = radiusY * cos(t);
		float z = 0;

		return { x, y, z };
	}

	void PrintPoint(float t) {
		float x = radiusX * cos(t) + center[0];
		float y = radiusY * sin(t) + center[1];
		float z = center[2];

		cout << "Point: (" << x << ", " << y << ", " << z << " )" << endl;
	}

	void PrintPointDerivative(float t) {
		float x = -radiusX * sin(t);
		float y = radiusY * cos(t);
		float z = 0;

		cout << "Derivative: (" << x << ", " << y << ", " << z << " )" << endl;
	}

	virtual bool IsCircle() {
		return false;
	}

	virtual bool IsEllipse() {
		return true;
	}

	virtual bool IsHelixe() {
		return false;
	}

	float GetRadius() {
		return 0; // заглушка
	}

};