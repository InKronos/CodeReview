#include "stdafx.h"



/*LinkedList<Tickets> getTicketsByPassenger(std::string firstName, std::string lastName, std::string password, MYSQL* conn) {

}*/

LinkedList<City> getCitysToList(MYSQL* conn) {
	MYSQL_ROW row;
	MYSQL_RES* res;
	LinkedList<City*> linkedList;
	std::string query = "SELECT * FROM Cities";
	const char* q = query.c_str();
	int qstate = mysql_query(conn, q);

	int i = 1;
	if (!qstate) {
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res)) {
			std::string name = row[1];
			int id = int(row[0]) - 48;
			City* city = new City(id, name);
			linkedList.add(city);
		}
		std::string city;
		std::cin >> city;
	}
	else {
		std::cout << "error";
	}
}