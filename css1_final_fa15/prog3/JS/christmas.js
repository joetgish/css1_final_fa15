//Kristine Laranjo
//16 December 2015
// CSS-1 Fa15 Final Exam Prog 3

function daysOfChristmas(num)
{
	for (var i = num; i >= 0; i--) { //loops through the number of days
		if (i == 1) //grammar check
		{
			document.write(i + " day of Christmas\n\n");
		}
		else if (i == 0)
		{
			document.write("Christmas is here!!\n\n");
		}
		else
		{
			document.write(i + " days of Christmas\n\n");
		}
	}
}

var days = 12; //declares and initializes days
daysOfChristmas(days); //calls function