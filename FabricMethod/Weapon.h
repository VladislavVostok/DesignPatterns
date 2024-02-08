#pragma once
#include<iostream>
#include "bullet.h"
using namespace std;

/*
* ����� ������������ ������
*/
class AbstractWeapon {
	protected:
		/*
		* ��������� ����� ��� �������� ����.
		*/
		virtual AbstractBullet* CreateBullet() = 0;
	private:
		Point3D location;
		Vector3D direction;
		double caliber;
	public:
		/*
		* ������� ��������� ������
		*/
		Point3D GetLocation() {
			return location;
		}
		void SetLocation(const Point3D& newLocation) {
			location = newLocation;
		}
		/*
		* ����������� ������
		*/
		Vector3D GetDirection(){
			return direction;
		} 
		void SetDirection(const Vector3D& newDirection) {
			direction = newDirection;
		}
		
		/*
		* ������ ������
		*/
		double GetCaliber() {
			return caliber;
		}
		void SetCaliber(double newCaliber) {
			caliber = newCaliber;
		}

		/*
		* �����, ������������ �������.
		* ���������� ��������� ��������� ����.
		*/
		AbstractBullet* Shoot(){
			// �������� ������� ���� � ������� ���������� ������
			AbstractBullet* bullet = CreateBullet();
			// ��������� ���� �� ������� ��������� ������
			bullet->SetCaliber(this->GetCaliber());
			bullet->SetLocation(this->GetLocation());
			bullet->SetDirection(this->GetDirection());
			// ������ �������� ����
			bullet->StartMovement();
			// ���������� ��������� ����
			return bullet;
		}
};

/*
* ����� ��������������� ������.
*/
class AutomaticWeapon : public AbstractWeapon
{
	public:
		AutomaticWeapon(){
			this->SetCaliber(20);
		}
	protected:
		/*
		* ���������� ���������� ������.
		* ������� ��������� ����,
		* ������������� ��� �������� ���� ������.
		*/
		AbstractBullet* CreateBullet(){
			return new AutomaticBullet();
		}
};

/*
* ����� ���������.
*/
class Shotgun : public AbstractWeapon
{
	public:
		Shotgun(){
			this->SetCaliber(50);
		}
	protected:
		/*
		* ���������� ���������� ������.
		* ������� ��������� ����,
		* ������������� ��� �������� ���� ������.
		*/
		AbstractBullet* CreateBullet()
		{
			return new ShotgunBullet();
		}
};