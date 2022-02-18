#pragma once

enum DDL_QUERY_INDEX
{
	DELETE_CASCADE_ON = 0,
	CREATE_TIMER_TABLE,
	DROP_TIMER_TABLE,
	CREATE_SELECT_TIMER_TABLE,
	DROP_SELECT_TIMER_TABLE,
};

enum DML_QUERY_INDEX
{
	UPDATE_AUTOINCREMENT_RESET_TIMER = 0,
	SELECT_ALL_TIMER_TABLE,
	SELECT_ONE_TIMER_TABLE,
	SELECT_ALL_SELECT_TIMER_TABLE,
	INSERT_TIMER_TABLE,
	UPDATE_TIMER_TABLE,
	DELETE_TIMER_TABLE,
	DELETE_ALL_TIMER_TABLE,
	INSERT_SELECT_TIMER_TABLE,
	UPDATE_SELECT_TIMER_TABLE,
	DELETE_SELECT_TIMER_TABLE,
};

static const char* DefinedDDLQuerys[] = { 
									// on delete cascade 
									"PRAGMA foreign_keys=ON",
									// create timer table
									"CREATE TABLE Timer(timerSEQ INTEGER PRIMARY KEY AUTOINCREMENT, \
																timerNAME TEXT, \
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
																allREPEAT INTEGER DEFAULT 0, \
																infREPEAT INTEGER DEFAULT 0, \
																muteSET INTEGER DEFAULT 0)",	
									// drop timer table
									"DROP TABLE Timer",	
									// create selectTimer table
									"CREATE TABLE SelectTimer(sl INTEGER DEFAULT 0)",
									// drop selectTimer table
									"DROP TABLE SelectTimer",
								  };

static const char* DefinedDMLQuerys[] = {
									// update timer primary key sequence reset
									"UPDATE SQLITE_SEQUENCE SET seq = 0 WHERE name = 'Timer'",
									// select all timer table 
									"SELECT * FROM Timer ORDER BY timerSEQ ASC",
									// select one timer table 
									"SELECT * FROM Timer WHERE timerSEQ = ?",
									// select all select timer table
									"SELECT * FROM SelectTimer",
									// insert timer table
									"INSERT INTO Timer (timerNAME, wkHOUR, wkMINUTE, wkSECOND, rsHOUR, rsMINUTE, rsSECOND, rfHOUR, rfMINUTE, rfSECOND, wrREPEAT, allREPEAT, infREPEAT, muteSET) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)",
									// update timer table
									"UPDATE Timer SET timerNAME = ?, wkHOUR = ?, wkMINUTE = ?, wkSECOND = ?, rsHOUR = ?, rsMINUTE = ?, rsSECOND = ?, rfHOUR = ?, rfMINUTE = ?, rfSECOND = ?, wrREPEAT = ?, allREPEAT = ?, infREPEAT = ?, muteSET = ? WHERE timerSEQ = ?",
									// delete timer table
									"DELETE FROM Timer WHERE timerSEQ = ?",
									// delete all timer table
									"DELETE FROM Timer",
									// insert select timer table
									"INSERT INTO SelectTimer (sl) VALUES (?)",
									// update select timer table
									"UPDATE SelectTimer SET sl = ?",
									// delete select timer table
									"DELETE FROM SelectTimer WHERE sl = ?"
								   };
