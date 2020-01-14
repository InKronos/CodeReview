#include "stdafx.h"


int main()
{
	std::cout << "Hello World";
	//auto conn = connection();
	MYSQL* conn;
	
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "1234", "FlightReservation", 3306, NULL, 0);
	if (conn) {
		while (1)
		{
			int choice = mainMenu();
			if (choice == 4) {
				break;
			}
			switch (choice)
			{
			case 1:
				RezervFlight(conn);
				std::cout << "hello";
				break;
			case 2:
				CancelFlight();
				break;
			case 3:
				ShowTickets();
				break;
			default:
				//TODO addicional comunicat
				break;
			}
		}
	}
	else {
		std::cout << "connection not up :(";
	}
	
}