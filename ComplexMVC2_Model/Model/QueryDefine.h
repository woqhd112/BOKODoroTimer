#pragma once

enum DDL_QUERY_INDEX
{
	DELETE_CASCADE_ON = 0,
	CREATE_TIMER_TABLE,
	DROP_TIMER_TABLE,
};

enum DML_QUERY_INDEX
{
	UPDATE_AUTOINCREMENT_RESET_TIMER = 0,
	SELECT_ALL_TIMER_TABLE,
	SELECT_ONE_TIMER_TABLE,
	INSERT_TIMER_TABLE,
	UPDATE_TIMER_TABLE,
	DELETE_TIMER_TABLE,
	DELETE_ALL_TIMER_TABLE,
};

static const char* DefinedDDLQuerys[] = { 
									// on delete cascade 
									"PRAGMA foreign_keys=ON",
									// create timer table
									"CREATE TABLE Timer(timerSEQ INTEGER PRIMARY KEY AUTOINCREMENT, \
																wkHOUR INTEGER DEFAULT 0, \
																wkMINUTE INTEGER DEFAULT 0, \
																wkSECOND INTEGER DEFAULT 0, \
																rsHOUR INTEGER DEFAULT 0, \
																rsMINUTE INTEGER DEFAULT 0, \
																rsSECOND INTEGER DEFAULT 0, \
																rfHOUR INTEGER DEFAULT 0, \
																rfMINUTE INTEGER DEFAULT 0, \
																rfSECOND INTEGER DEFAULT 0, \
																wrREPEAT INTEGER DEFAULT 1, \
																allREPEAT INTEGER DEFAULT 0)",	
									// drop timer table
									"DROP TABLE Timer",	

								  };

static const char* DefinedDMLQuerys[] = {
									// update timer primary key sequence reset
									"UPDATE SQLITE_SEQUENCE SET seq = 0 WHERE name = 'Timer'",
									// select all timer table 
									"SELECT * FROM Timer ORDER BY timerSEQ ASC",
									// select one timer table 
									"SELECT * FROM Timer WHERE timerSEQ = ?",
									// insert timer table
									"INSERT INTO Timer (wkHOUR, wkMINUTE, wkSECOND, rsHOUR, rsMINUTE, rsSECOND, rfHOUR, rfMINUTE, rfSECOND, wrREPEAT, allREPEAT) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)",
									// update timer table
									"UPDATE Timer SET wkHOUR = ?, wkMINUTE = ?, wkSECOND = ?, rsHOUR = ?, rsMINUTE = ?, rsSECOND = ?, rfHOUR = ?, rfMINUTE = ?, rfSECOND = ?, wrREPEAT = ?, allREPEAT = ? WHERE timerSEQ = ?",
									// delete timer table
									"DELETE FROM Timer WHERE timerSEQ = ?",
									// delete all timer table
									"DELETE FROM Timer",
								   };
