// Name: Samuel Sanchez
// Date: 17 December 2015
// CSS-1 Fa15 Final Exam Prog 3

function xmasPrint() // Prints out 12 days of christmas
{
	document.write("Samuel Sanchez\t");
	var daysTill = 12; // Countdown of days
	for(var xi = daysTill; xi > 0; xi--)
	{
		document.write(xi + " days of Christmas\n");
	}
	document.write("Christmas is here!!\n");
}

xmasPrint();