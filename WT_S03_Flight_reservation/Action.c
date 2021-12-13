Action()
{

	web_set_sockets_option("SSL_VERSION","AUTO");
	web_set_max_html_param_len("1024");
	web_cleanup_cookies();
	web_cleanup_auto_headers();
	web_cache_cleanup();
	
	/* **********Launch_Page************** */
	
	

	web_reg_find("SaveCount=LaunchpageC",
		"Text/IC=Welcome to the Web Tours site.",
		LAST);
	
//<input type="hidden" name="userSession" value="132768.658404212zicQciHpizzzzzzHtAQHfpHcHc"/>
	web_reg_save_param_regexp(
		"ParamName=U_Session_Id",
		"RegExp=name=\"userSession\" value=\"(.*?)\"/>",
		"Ordinal=1",
		LAST);

	

	lr_start_transaction("WT_S03_FB_T01_Launch_page");


	web_url("index.htm", 
		"URL=http://127.0.0.1:1080/webtours/index.htm", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
  
   i=atoi(lr_eval_string("{LaunchpageC}"));
  
   if (i>0)
   {
     lr_output_message("Login_Page_Successful");
     lr_end_transaction("WT_S03_FB_T01_Launch_page", LR_PASS);
  }
  else
  {
  	  lr_output_message("Login_Page_Failed");
  	  lr_end_transaction("WT_S03_FB_T01_Launch_page", LR_FAIL);
  	  lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
  	
  }
  	
	/*************** Login************* */
	
	lr_think_time(thinktime);


	web_reg_find("SaveCount=LoginC",
		"Text/IC=Welcome,",
		LAST);
	
	lr_start_transaction("WT_S03_FB_T02_Login_page");


	web_submit_data("login.pl", 
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value={U_Session_Id}", ENDITEM, 
		"Name=username", "Value={Uname}", ENDITEM, 
		"Name=password", "Value={Password}", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=46", ENDITEM, 
		"Name=login.y", "Value=5", ENDITEM, 
		LAST);
	
	
	i=atoi(lr_eval_string("{LoginC}"));
	if(i>0)
	{
		lr_output_message("Login_Page_Pass");
		lr_end_transaction("WT_S03_FB_T02_Login_page", LR_PASS);
}
else
{
		lr_output_message("Login_Page_Failed");	  	 
		lr_end_transaction("WT_S03_FB_T02_Login_page", LR_FAIL);
	  	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
  	
}
	
	

	web_reg_save_param_regexp(
		"ParamName=Cities",
		"RegExp=<option[ , A-Z,a-z,=,\\\"]+value=\\\"([A-Z,a-z, ]+)\\\">[A-Z,a-z, ]+</option>",
		"Ordinal=ALL",
		LAST);
		
		//name="seatPref" value="Window" />
		
		
/*		web_reg_save_param_regexp(
		"ParamName=SeatPref",
		"RegExp=<input type=[ , A-Z,a-z,=,\"]+value=\"((.*?))\" />(.*?)</label",
		"Group=1",
		"Ordinal=All",
		LAST);
		*/

web_reg_save_param("seatPref",
 "LB=name=\"seatPref\" value=\"",
 "RB=\" />",
 "ORD=all",
 LAST);

//name="seatType" value="Business" />

web_reg_save_param("seatType",
 "LB=name=\"seatType\" value=\"",
 "RB=\" />",
 "ORD=all",
 LAST);

	
	

	/* Find Flights */
	
		lr_think_time(thinktime);
	
	lr_start_transaction("WT_S03_FB_T03_Find_Flight");


	web_reg_find("SaveCount=FFlightC",
		"Text/IC=Find Flight",
		LAST);
	
	
	

//Correlation comment - Do not change!  Original value='Window' Name ='seatPref' Type ='Manual'
	web_reg_save_param_attrib(
		"ParamName=seatPref",
		"TagName=input",
		"Extract=value",
		"Name=seatPref",
		"Type=radio",
				LAST);
/*orrelation comment - Do not change!  Original value='Aisle' Name ='seatType' Type ='Manualut",
		"Extract=value",
		"Name=seatPref",
		"Type=radio",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=reservations.pl*",
		LAST);
*/
	
	web_url("Search Flights Button",
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
	
	i=atoi(lr_eval_string("{FFlightC}"));
	if(i>0)
	{
		lr_output_message("Find_Flight_Page_Pass");
		lr_end_transaction("WT_S03_FB_T03_Find_Flight", LR_PASS);
}
else
{
		lr_output_message("Find_Flight_Page_Failed");	  	 
		lr_end_transaction("WT_S03_FB_T03_Find_Flight", LR_FAIL);
	  	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
  	
}


	lr_think_time(thinktime);

	/* Select Flight */
	
/*	random_D_City=lr_paramarr_random("Cities");
	//lr_save_string(random_D_City,"Prandom_D_City");   //we have two functions  use what ever you wan
	lr_param_sprintf("Prandom_D_City","%s",random_D_City);
	
	random_A_City=lr_paramarr_random("Cities");
	lr_param_sprintf("Prandom_A_City","%s",random_A_City);
	
	*/
	
	
	
j=lr_paramarr_len("Cities");

k=lr_paramarr_len("Cities");

for(i=1;i<=k;i++)
{
temp=lr_paramarr_idx("Cities",i);
lr_save_int(j+1,"newint");
lr_save_string(temp,lr_eval_string("Cities_{newint}"));
j++;
}


CitySelection:
{
i=rand()%20+1;
temp1=lr_paramarr_idx("Cities",i);
lr_save_string(temp1,"FromCity");

i=rand()%20+1;
temp2=lr_paramarr_idx("Cities",i);
lr_save_string(temp2,"ToCity");

}

i=strcmp(temp1,temp2);

if(i==0)
{
goto CitySelection;
}

i=rand()%3+1;

temp=lr_paramarr_idx("seatPref",i);

token=(char *)strtok(temp,"\"");

	lr_param_sprintf("seatPref","%s",token);

//lr_save_string(token,"seatPrf");

i=rand()%3+1;

temp=lr_paramarr_idx("seatType",i);

token=(char *)strtok(temp,"\"");

lr_save_string(token,"seatType");


	//temp=lr_paramarr_random("Flight");

//token=(char *)strtok(temp," ");

//lr_save_string(token,"FlightSelected");

	
	
	
	
	

	lr_think_time(thinktime);
	
	//radio name=outboundFlight value=242;149;07/25/2012>
	//input type="radio" name="outboundFlight" value="421;97;12/12/2021">B

web_reg_save_param("Flight",
 "LB=name=\"outboundFlight\" value=\"",
 "RB=>",
 "ORD=all",
 LAST);

	
	lr_start_transaction("WT_S03_FB_T04_Select_Flight");


	web_reg_find("SaveCount=SFlight",
		"Text/IC=Flight departing from",
		LAST);

	web_submit_data("reservations.pl",
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl?page=welcome",
		"Snapshot=t4.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=depart", "Value={FromCity}", ENDITEM,
		"Name=departDate", "Value=12/12/2021", ENDITEM,
		"Name=arrive", "Value={ToCity}", ENDITEM,
		"Name=returnDate", "Value=15/11/2021", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=.cgifields", "Value=roundtrip", ENDITEM,
		"Name=.cgifields", "Value=seatType", ENDITEM,
		"Name=.cgifields", "Value=seatPref", ENDITEM,
		"Name=findFlights.x", "Value=50", ENDITEM,
		"Name=findFlights.y", "Value=8", ENDITEM,
		LAST);
	
	i=atoi(lr_eval_string("{SFlight}"));
	if(i>0)
	{
		lr_output_message("Select_Flight_Page_Pass");
		lr_end_transaction("WT_S03_FB_T04_Select_Flight", LR_PASS);
}
else
{
		lr_output_message("Select_Flight_Page_Failed");	  	 
		lr_end_transaction("WT_S03_FB_T04_Select_Flight", LR_FAIL);
	  	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
  	
}

/*************Payment_dtls******************/

	lr_think_time(thinktime);
	
	lr_start_transaction("WT_S03_FB_T05_Payment_dtls");

	
	temp=lr_paramarr_random("Flight");

token=(char *)strtok(temp," ");

lr_save_string(token,"FlightSelected");


	web_reg_find("SaveCount=PaymentC",
		"Text/IC=Payment Details",
		LAST);

	web_submit_data("reservations.pl_2", 
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={FlightSelected}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=reserveFlights.x", "Value=59", ENDITEM, 
		"Name=reserveFlights.y", "Value=14", ENDITEM, 
		LAST);
		
		
		i=atoi(lr_eval_string("{PaymentC}"));
	if(i>0)
	{
		lr_output_message("Payment_Page_Pass");
		lr_end_transaction("WT_S03_FB_T05_Payment_dtls", LR_PASS);
}
else
{
		lr_output_message("Payment_Page_Failed");	  	 
		lr_end_transaction("WT_S03_FB_T05_Payment_dtls", LR_FAIL);
	  	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
  	
}
		
	
	/*************Invoice******************/

	lr_think_time(thinktime);
	
	lr_start_transaction("WT_S03_FB_T06_Invoice_Page");


	web_reg_find("SaveCount=InvoiceC",
		"Text/IC=Invoice",
		LAST);

	web_submit_data("reservations.pl_3", 
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value={Uname}", ENDITEM, 
		"Name=lastName", "Value={Password}", ENDITEM, 
		"Name=address1", "Value=bly", ENDITEM, 
		"Name=address2", "Value=KA", ENDITEM, 
		"Name=pass1", "Value=Jojo Bean", ENDITEM, 
		"Name=creditCard", "Value=9844556677878", ENDITEM, 
		"Name=expDate", "Value=12/24", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=outboundFlight", "Value={FlightSelected}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		"Name=buyFlights.x", "Value=40", ENDITEM, 
		"Name=buyFlights.y", "Value=6", ENDITEM, 
		LAST);
	
	
	
	i=atoi(lr_eval_string("{InvoiceC}"));
	if(i>0)
	{
		lr_output_message("Invoice_Page_Pass");
		lr_end_transaction("WT_S03_FB_T06_Invoice_Page", LR_PASS);
}
else
{
		lr_output_message("Invoice_Page_Failed");	  	 
		lr_end_transaction("WT_S03_FB_T06_Invoice_Page", LR_FAIL);
	  	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
  	
}
	
	
	
	/*******Book_another***********/

	lr_think_time(thinktime);
	
	lr_start_transaction("WT_S03_FB_T07_Book_Another_Page");


	web_reg_find("SaveCount=BACount",
		"Text/IC=Find Flight",
		LAST);

	web_submit_data("reservations.pl_4", 
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=Book Another.x", "Value=24", ENDITEM, 
		"Name=Book Another.y", "Value=8", ENDITEM, 
		LAST);
	
	i=atoi(lr_eval_string("{BACount}"));
	if(i>0)
	{
		lr_output_message("Book_Another_Page_Pass");
		lr_end_transaction("WT_S03_FB_T07_Book_Another_Page", LR_PASS);
}
else
{
		lr_output_message("Book_Another_Page_Failed");	  	 
		lr_end_transaction("WT_S03_FB_T07_Book_Another_Page", LR_FAIL);
	  	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
  	
}
	
	
	
	/******LogOff**********/

	lr_think_time(thinktime);
	
	lr_start_transaction("WT_S03_FB_T08_LogOff_Page");


	web_reg_find("SaveCount=SignoffC",
		"Text/IC=Username",
		LAST);

	web_url("SignOff Button", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);
	
	i=atoi(lr_eval_string("{SignoffC}"));
	
	if(i>0)
	{
		lr_output_message("LogOff_Page_Pass");
		lr_end_transaction("WT_S03_FB_T08_LogOff_Page", LR_PASS);
}
else
{
		lr_output_message("LogOff_Page_Failed");	  	 
		lr_end_transaction("WT_S03_FB_T08_LogOff_Page", LR_FAIL);
	  	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
  	
}

	return 0;
}