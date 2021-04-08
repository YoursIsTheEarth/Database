#include <iostream>
#include "Database.h"
#include "Table.h"
#include "Record.h"

using namespace std;

int notMain()
{
	Database db = Database();
	Table tb = Table();
	db.add(tb, "table");
	db.drop("table");
	db.save("file");
	db.load("file");
	db.listTable();
	db.getTables();
	db.query("select", "from", "where");

	/*create test values/structres */
	vector<string> vec;
	vector<string> attributes = { "Name, Town, State" };
	Record rec(5);
	/*Test Constructor*/
	Table table1(attributes);
	Table table2, table3, table4;
	Table *t;


	/*Test various functions*/
	vec = table1.get_attributes();
	table1.add_attribute("town");
	table1.delete_attribute("town");
	table1.add_record(rec);
	vec = table1.get_attributes();
	int size = table1.get_table_size();
	table1.assign_key("Key");
	table1.count_entries("town");
	table1.min("town");
	table1.max("town");

	/*Test cross-join and natural-join*/
	t = cross_join(table1, table2);
	t = natural_join(table1, table2);

	map<string, Record>::const_iterator it;
	/*
	int m = 0;
	for (it = table2.begin(); it != table2.end(); it++) {
		cout << it->first << endl;
		m++;
	}
	*/
	Record r1;

	r1 = table3.find_record("jim");

	rec.size();
	rec.set(2, "Jack");
	rec.get(2);
	system("pause");

	return 0;
}