#pragma once

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


#include"tms.h"

void Menu()
{
	cout << "------------------ Welcome to Transport Management System ------------------" << endl;
	bool flag = false;
	int choice;
	tms t;

	while (!flag)
	{
		t.updateCount();

		cout << "____________________________________________________________________________" << endl
			<< "[1] Add a New Customer" << endl//
			<< "[2] Add a New Driver" << endl//
			<< "[3] Remove a Driver" << endl//
			<< "[4] Add a New Vehicle" << endl//
			<< "[5] Remove a Vehicle" << endl//
			<< "[6] Print List of All Customers" << endl//
			<< "[7] Print List of All Drivers" << endl//
			<< "[8] Print List of All Vehicles with Details by their Category" << endl//
			<< "[9] Print Details & Service History of a Vehicle" << endl  //vid//
			<< "[10] Print History of a Customer" << endl  //cid//
			<< "[11] Print History of a Driver with Services" << endl  //did//
			<< "[12] Print List of All Driver with Ranking 4.5+" << endl//
			<< "[13] Print List of All Drivers with Multiple Licences" << endl//
			<< "[14] Print Updated Salary of All Drivers" << endl
			<< "[15] Add a Servive Request" << endl//
			<< "[16] Cancel a Service" << endl//
			<< "[17] Complete a Service" << endl //service id
			<< "[18] Print Details of All Customers who used same Vehicle" << endl//
			<< "[19] Print List of all Drivers who completed Delivery Service same Day" << endl
			<< "[20] Print details of all pending services on a particular date" << endl//
			<< "[21] Print details of all pending services of a particular driver" << endl
			<< "[22] Print details of all canceled services by a customer" << endl
			<< "[23] Any other Button to Exit the Program" << endl//
			<< "____________________________________________________________________________" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			t.addCostumer();
			break;

		case 2:
			t.addDriver();
			break;

		case 3:
			t.removeDriver();
			break;

		case 4:
			t.addVehicle();
			break;

		case 5:
			t.removeDriver();
			break;

		case 6:
			t.displayAllCostumers();
			break;

		case 7:
			t.displayAllDrivers();
			break;

		case 8:
			t.displayAllVehicles();
			break;

		case 9:
			t.detailHistoryOfVehicle();
			break;

		case 10:
			t.historyOfcostumer();
			break;

		case 11:
			t.HistoryOfDriver();
			break;

		case 12:
			t.driverWithRating();
			break;

		case 13:
			t.driversWithMultipleLiscences();
			break;

		case 14:
			t.printSalary();
			break;

		case 15:
			t.addService();
			break;

		case 16:
			t.cancelService();
			break;

		case 17:
			t.completeService();
			break;

		case 18:
			t.listOfCostumersWithSameVehicle();
			break;

		case 19:

			break;

		case 20:
			t.listOfServicesOnDate();
			break;

		case 21:
			t.pendingServices();
			break;

		case 22:
			break;

		default:
			flag = true;
			break;
		}
	}
		
}

int main() 

{
	Menu();
	return 0;
}