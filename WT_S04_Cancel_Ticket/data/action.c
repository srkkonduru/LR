Action()
{

	web_add_auto_header("Accept-Language", 
		"en-IN,en-US;q=0.7,en;q=0.3");

	web_url("index.htm", 
		"URL=http://127.0.0.1:1080/webtours/index.htm", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	/* Login */

	lr_think_time(13);

	web_submit_data("login.pl", 
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=132783.44163629ziDAAtipcHQVzzzHtAQiApciQzHf", ENDITEM, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=50", ENDITEM, 
		"Name=login.y", "Value=11", ENDITEM, 
		LAST);

	/* Itinerary */

	web_url("Itinerary Button", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	/* select Cancel flight */

	/* click cancel checked */

	lr_think_time(23);

	web_submit_data("itinerary.pl", 
		"Action=http://127.0.0.1:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=flightID", "Value=29179340-84-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-161-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-238-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-315-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-392-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-469-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-545-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-622-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-699-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-776-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-853-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-930-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-1007-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-1084-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-1161-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-1238-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-1315-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-1392-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-1469-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-1545-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-1622-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-1699-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-1776-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-1853-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-1930-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-2007-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-2084-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-2161-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-2238-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-2315-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-2392-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-2469-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-2545-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-2622-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-2699-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-2776-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-2853-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-2930-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-3007-JB", ENDITEM, 
		"Name=flightID", "Value=29179340-3084-JB", ENDITEM, 
		"Name=flightID", "Value=291789310-31567-JB", ENDITEM, 
		"Name=flightID", "Value=291778898-32327-JB", ENDITEM, 
		"Name=flightID", "Value=291803382-33102-JB", ENDITEM, 
		"Name=flightID", "Value=291805931-33858-jb", ENDITEM, 
		"Name=flightID", "Value=291813762-34659-jb", ENDITEM, 
		"Name=flightID", "Value=287638210-35437-JB", ENDITEM, 
		"Name=.cgifields", "Value=33", ENDITEM, 
		"Name=.cgifields", "Value=32", ENDITEM, 
		"Name=.cgifields", "Value=21", ENDITEM, 
		"Name=.cgifields", "Value=7", ENDITEM, 
		"Name=.cgifields", "Value=26", ENDITEM, 
		"Name=.cgifields", "Value=17", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=18", ENDITEM, 
		"Name=.cgifields", "Value=30", ENDITEM, 
		"Name=.cgifields", "Value=16", ENDITEM, 
		"Name=.cgifields", "Value=44", ENDITEM, 
		"Name=.cgifields", "Value=27", ENDITEM, 
		"Name=.cgifields", "Value=25", ENDITEM, 
		"Name=.cgifields", "Value=28", ENDITEM, 
		"Name=.cgifields", "Value=40", ENDITEM, 
		"Name=.cgifields", "Value=20", ENDITEM, 
		"Name=.cgifields", "Value=14", ENDITEM, 
		"Name=.cgifields", "Value=24", ENDITEM, 
		"Name=.cgifields", "Value=10", ENDITEM, 
		"Name=.cgifields", "Value=31", ENDITEM, 
		"Name=.cgifields", "Value=35", ENDITEM, 
		"Name=.cgifields", "Value=11", ENDITEM, 
		"Name=.cgifields", "Value=42", ENDITEM, 
		"Name=.cgifields", "Value=22", ENDITEM, 
		"Name=.cgifields", "Value=46", ENDITEM, 
		"Name=.cgifields", "Value=13", ENDITEM, 
		"Name=.cgifields", "Value=23", ENDITEM, 
		"Name=.cgifields", "Value=29", ENDITEM, 
		"Name=.cgifields", "Value=6", ENDITEM, 
		"Name=.cgifields", "Value=39", ENDITEM, 
		"Name=.cgifields", "Value=36", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=9", ENDITEM, 
		"Name=.cgifields", "Value=41", ENDITEM, 
		"Name=.cgifields", "Value=12", ENDITEM, 
		"Name=.cgifields", "Value=15", ENDITEM, 
		"Name=.cgifields", "Value=38", ENDITEM, 
		"Name=.cgifields", "Value=8", ENDITEM, 
		"Name=.cgifields", "Value=4", ENDITEM, 
		"Name=.cgifields", "Value=34", ENDITEM, 
		"Name=.cgifields", "Value=45", ENDITEM, 
		"Name=.cgifields", "Value=37", ENDITEM, 
		"Name=.cgifields", "Value=43", ENDITEM, 
		"Name=.cgifields", "Value=19", ENDITEM, 
		"Name=.cgifields", "Value=5", ENDITEM, 
		"Name=removeFlights.x", "Value=70", ENDITEM, 
		"Name=removeFlights.y", "Value=3", ENDITEM, 
		LAST);

	/* Logoff */

	lr_think_time(11);

	web_url("SignOff Button", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	return 0;
}