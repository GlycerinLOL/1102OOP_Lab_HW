#include "Diary.h"
#include "Creature.h"

int main() {

	Diary::NewDay("-2000");
	Diary::NewDay("-1050");
	Creature Hourse("Hourse");
	Hourse["leg"] = 4;
	Hourse["hand"] = 2;
	Diary::NewDay("-1000");
	Hourse["leg"] += 1;
	Hourse["hand"] -= 1;
	Diary::NewDay("-950");
	Hourse["leg"] += 1;
	Hourse["hand"] -= 1;
	Diary::NewDay("-950");
	Hourse["hand"] = 0;
	Creature Hourse2("Hourse2", Hourse);
	Hourse2.PrintLog();
	Diary::NewDay("1000");
	Hourse2.PrintStatus();
	Hourse["horn"] += 1;
	Diary::NewDay("1220");
	Hourse2["wing"] -= -2;
	Hourse.PrintLog();
	Hourse.PrintStatus();
	Diary::NewDay("4320");
	Hourse2.PrintLog();
	Hourse2.PrintStatus();
	Diary::NewDay("5500OwO");


}

