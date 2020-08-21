#include <vector>

#define PI 3.1415926535;

using namespace std;
class CentralPoint {
protected:
	vector<float> center;

public:
	CentralPoint() {
		center = { 0, 0, 0 };
	}

	CentralPoint(vector<float> _center) {
		center = { 0, 0, 0 };
		try {
			if (_center.size() != 3) {
				throw 2;
			}
			center = _center;
		}
		catch (int exeptionID) {
			cout << "Error " << exeptionID << " size of vector != 3" << endl;
		}
	}

	virtual vector<float> GetPoint(float t) { return { 0, 0, 0 }; }
	virtual vector<float> GetPointDerivative(float t) { return { 0, 0, 0 }; }
	virtual void PrintPoint(float t) {}
	virtual void PrintPointDerivative(float t) {}
	virtual float GetRadius() { return 0; }
	virtual bool IsCircle() { return false; }
	virtual bool IsEllipse() { return false; }
	virtual bool IsHelixe() { return false; }
	virtual void Print() { }

	vector<float> GetCenter() {
		return center;
	}
};