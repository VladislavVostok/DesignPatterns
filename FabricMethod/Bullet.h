#pragma once
#include<iostream>
using namespace std;

/*
* ����� � ���������� ������������.
* ������������ ��� ����������� ���������.
*/
struct Point3D {
	int X;
	int Y;
	int Z;
};

/*
* ������ � ���������� ������������.
* ������������ ��� ����������� �����������.
*/
struct Vector3D {
	int X;
	int Y;
	int Z;
};

/*
* ����� ����������� ����.
*/
class AbstractBullet
{
	private:
		Point3D location;
		Vector3D direction;
		double caliber;
public:
	/*
	* ������� ��������� ����
	*/
	Point3D GetLocation() {
		return location;
	}
	void SetLocation(const Point3D& newLocation) {
		location = newLocation;
	}
	/*
	* ����������� ����
	*/
	Vector3D GetDirection() {
		return direction;
	}
	void SetDirection(const Vector3D& newDirection) {
		direction = newDirection;
	}

	/*
	* ������ ����
	*/
	double GetCaliber() {
		return caliber;
	}
	void SetCaliber(double newCaliber) {
		caliber = newCaliber;
	}

	/*
	* ������ �������� ����.
	*/
	void StartMovement()
	{
		// ���������� ������ ��������
	}
	/*
	* ����� ��������� ����.
	* ��� ��� ������ ���� ���� �������� ���� ��-�������,
	* �� ����� ������ ���� ���������� � ����������.
	*/
	virtual void HitTarget(void* target) = 0;
	/*
	* �����, ����������� �������� ����.
	* ��� ��� ������ ���� ���� ����� ������ ���������� ��������,
	* �� ����� ������ ���� ���������� � ����������.
	*/
	virtual void Movement() = 0;
};

/*
* ����� ���� ��� ��������������� ������.
*/
class AutomaticBullet : public AbstractBullet
{
	public:
		void HitTarget(void* target){
			// ���������� ��������� ���� target
			cout << "Hit by automatic bullet\n";
		}
		void Movement(){
			// ���������� ��������� �������� ����
		}
};

/*
* ����� ���� ��� ���������.
*/
class ShotgunBullet : public AbstractBullet
{
	public:
		void HitTarget(void* target){
			// ���������� ��������� ���� target
			cout << "Hit by shotgun bullet\n";
		}
		void Movement(){
			// ���������� ��������� �������� ����
		}
};