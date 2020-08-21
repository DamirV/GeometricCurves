#include <ctime>
#include <algorithm>
#include "GeometricCurves.h"

using namespace std;

void Dash() {
	for (int i = 0; i < 20; ++i) {
		cout << "-";
	}
	cout << endl;
}

int main()
{
	srand(time(NULL));

	float pi = PI;
	float t = pi / 4;
	vector<CentralPoint*> arr1;
	vector<CurveCircle> arr2;
	int circleCount = 0;
	int ellipseCount = 0;
	int helixeCount = 0;

	while (circleCount * ellipseCount * helixeCount == 0) {

		for (int i = 0; i < 10; ++i) {
			int flag = rand() % 3;
			vector<float> center = { static_cast <float>(rand() % 100 - 50),
			static_cast <float>(rand() % 100 - 50),
			static_cast <float>(rand() % 100 - 50) };

			switch (flag) {

			case 0:
				arr1.push_back(new CurveCircle(center, static_cast <float>(rand() % 50)));
				circleCount++;
				break;

			case 1:
				arr1.push_back(new CurveEllipse(center, static_cast <float>(rand() % 50), static_cast <float>(rand() % 50)));
				ellipseCount++;
				break;

			case 2:
				arr1.push_back(new CurveHelixe(center, static_cast <float>(rand() % 50), static_cast <float>(rand() % 50)));
				helixeCount++;
				break;
			}
		}
	}

	Dash();
	cout << "Size of the arr1: " << arr1.size() << endl;

	for (int i = 0; i < arr1.size(); ++i) {
		arr1[i]->Print();
		arr1[i]->PrintPoint(t);
		arr1[i]->PrintPointDerivative(t);
		cout << endl;

		if (arr1[i]->IsCircle()) {
			arr2.push_back( CurveCircle(arr1[i]->GetCenter(), arr1[i]->GetRadius()));
		}
	}

	Dash();
	cout << "Size of the arr2: " << arr2.size() << endl;

	
	float sumRadius = 0;
	for (int i = 0; i < arr2.size(); ++i) {
		arr2[i].Print();
		sumRadius += arr2[i].GetRadius();
	}

	Dash();
	cout << "Sum of the radiuses: " << sumRadius << endl;

	sort(arr2.begin(), arr2.end());

	Dash();
	cout << "After sorting: " << sumRadius << endl;

	for (int i = 0; i < arr2.size(); ++i) {
		arr2[i].Print();
	}
}
