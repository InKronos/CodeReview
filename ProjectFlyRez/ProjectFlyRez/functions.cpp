#include "stdafx.h"

/*MYSQL * connection() {
	
}
*/


int mainMenu() {
	std::cout << "What you want? \n";
	std::cout << "Flight rez 1 \n";
	std::cout << "cancel tickets \n";
	std::cout << "show tickets \n";
	std::cout << "exit 4 \n \n";
	std::cout << "your choice: ";
	int choice;
	std::cin >> choice;
	return choice;
}


void RezervFlight(MYSQL * conn) {
	MYSQL_ROW row;
	MYSQL_RES* res;
	std::string query = "SELECT * FROM Cities";
	const char* q = query.c_str();
	int qstate = mysql_query(conn, q);
	
	int i = 1;
	if (!qstate) {
		std::cout << "Type your source city: " << std::endl;
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res)) {
			std::cout << i << ". " << row[1] << std::endl;
			i++;
		}
		std::string city;
		std::cin >> city;
		std::cout << "your city" << city;
	}
	else {
		std::cout << "error";
	}
	
}

void CancelFlight() {
	//TODO show tikets by human
	
}
void ShowTickets() {
	//TODO show tikets by human
}