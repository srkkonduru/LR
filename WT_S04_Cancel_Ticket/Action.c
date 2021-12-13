Action()
{

	

/*Correlation comment - Do not change!  Original value='132783.44163629ziDAAtipcHQVzzzHtAQiApciQzHf' Name ='userSession' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=userSession",
		"LB=name=\"userSession\" value=\"",
		"RB=\"/>\n<table border",
		
		LAST);
		
		lr_start_transaction("S04_WT_Cancel_T01_LaunchPage");


	web_reg_find("SaveCount=LaunchC",
		"Text/IC=Web Tours",
		LAST);

	web_url("index.htm", 
		"URL=http://127.0.0.1:1080/webtours/index.htm", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
		
		i=atoi(lr_eval_string("{LaunchC}"));
		
		if(i>0)
		{
			lr_output_message("Launch_Page_Successful");
			lr_end_transaction("S04_WT_Cancel_T01_LaunchPage", LR_PASS);
			
		}
		else
		{
	    	lr_output_message("Launch_Page_Failed");			
	    	lr_end_transaction("S04_WT_Cancel_T01_LaunchPage", LR_FAIL);
		}


	/* Login */

	lr_think_time(10);
	
	lr_start_transaction("S04_WT_Cancel_T02_LoginPage");


	web_reg_find("SaveCount=LoginC",
		"Text/IC=Welcome",
		LAST);

	web_submit_data("login.pl",
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t2.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value=jojo", ENDITEM,
		"Name=password", "Value=bean", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=login.x", "Value=50", ENDITEM,
		"Name=login.y", "Value=11", ENDITEM,
		LAST);
	
	i=atoi(lr_eval_string("{LoginC}"));
		
		if(i>0)
		{
			lr_output_message("Login_Page_Successful");
			lr_end_transaction("S04_WT_Cancel_T02_LoginPage", LR_PASS);
			
		}
		else
		{
		lr_output_message("Login_Page_Failed");			
		lr_end_transaction("S04_WT_Cancel_T02_LoginPage", LR_FAIL);
		}

	/* Itinerary */
	
	lr_start_transaction("S04_WT_Cancel_T03_itinerary");


	web_reg_find("SaveCount=itinerary",
		"Text/IC=Itinerary",
		LAST);

/*Correlation comment - Do not change!  Original value='29179340-84-JB' Name ='flightID' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=flights",
		"LB=name=\"flightID\" value=\"",
		"RB=\"  ",
		"Ordinal=ALL",
		LAST);
		


	web_url("Itinerary Button", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	i=atoi(lr_eval_string("{itinerary}"));
		
		if(i>0)
		{
			lr_output_message("itinarery_Page_Pass");
			lr_end_transaction("S04_WT_Cancel_T03_itinerary", LR_PASS);
			
		}
		else
		{
		lr_output_message("itinarery_Page_Failed");			
		lr_end_transaction("S04_WT_Cancel_T03_itinerary", LR_FAIL);
		}


	/* select Cancel flight click cancel checked */

	lr_think_time(10);
	
//	temp=lr_paramarr_random("flights");
//lr_save_string(temp,"flights");
	
	lr_start_transaction("S04_WT_Cancel_T04_cancel");

	web_reg_find("SaveCount=cancel",
		"Text/IC=Flight Transaction Summary",
		LAST);

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
		"Name=flightID", "Value={flights}", ENDITEM,
		"Name=.cgifields", "Value=33", ENDITEM,
		"Name=removeFlights.x", "Value=70", ENDITEM,
		"Name=removeFlights.y", "Value=3", ENDITEM,
		LAST);
	
	i=atoi(lr_eval_string("{cancel}"));
		
		if(i>0)
		{
			lr_output_message("Cancel_Page_Pass");
			lr_end_transaction("S04_WT_Cancel_T04_cancel", LR_PASS);
			
		}
		else
		{
		lr_output_message("Cancel_Page_Failed");			
		lr_end_transaction("S04_WT_Cancel_T04_cancel", LR_FAIL);
		}
	

	/* Logoff */

	lr_think_time(11);
	
	lr_start_transaction("WT_S04_Cancel_T05_LogOff_Page");


	web_reg_find("SaveCount=Logoff",
		"Text/IC=Username",
		LAST);

	web_url("SignOff Button", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);
	
	i=atoi(lr_eval_string("{Logoff}"));
	
	if(i>0)
	{
		lr_output_message("LogOff_Page_Pass");
		lr_end_transaction("WT_S04_Cancel_T05_LogOff_Page", LR_PASS);
}
else
{
		lr_output_message("LogOff_Page_Failed");	  	 
		lr_end_transaction("WT_S04_Cancel_T05_LogOff_Page", LR_FAIL);
	  	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
  	
}

	return 0;
}