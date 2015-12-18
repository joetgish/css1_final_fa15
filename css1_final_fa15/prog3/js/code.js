// Name: Samuel Sanchez
// Date: 17 December 2015
// CSS-1 Fa15 Final Exam Prog 3

function xmasPrint() // Prints out 12 days of christmas (start)
{
	document.write("Samuel Sanchez");
	var daysTill = 12; // Countdown of days
	for(var xi = daysTill; xi > 0; xi--)
	{
		document.write("<p>" + xi + " days of Christmas</p>"); // <p> added for line skipping
	}
	document.write("Christmas is here!!"); 
} // End of function

xmasPrint();