#pragma once

MYSQL* connection();
int ** makegraf();
int mainMenu();
void RezervFlight(MYSQL* conn);
void CancelFlight();
void ShowTickets();