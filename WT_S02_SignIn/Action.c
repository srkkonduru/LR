Action()
{
		web_set_sockets_option("SSL_VERSION", "AUTO");
		web_cleanup_cookies();
		web_cache_cleanup();
		

/*Correlation comment - Do not change!  Original value='132748.816929931ziciczHpcHAiDDDDtAQzQpzADzcf' Name ='userSession' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=userSession",
		"TagName=input",
		"Extract=value",
		"Name=userSession",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);
		
		lr_start_transaction("S02_WT_Login_T01_LaunchPage");


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
			lr_end_transaction("S02_WT_Login_T01_LaunchPage", LR_PASS);
			
		}
		else
		{
		lr_output_message("Launch_Page_Failed");			
		lr_end_transaction("S02_WT_Login_T01_LaunchPage", LR_FAIL);
		}

		
		

		
	/*	web_image_check("web_image_check",
		"Alt=Login",
		LAST);
*/
	/* Login */

	lr_think_time(thinktime);
	
	lr_rendezvous("Loginpage_Loginscript");
	
	lr_start_transaction("S02_WT_Login_T02_Login_Page");


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
		"Name=username", "Value={Usr_Name}", ENDITEM,
		"Name=password", "Value={Password}", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=login.x", "Value=54", ENDITEM,
		"Name=login.y", "Value=8", ENDITEM,
		LAST);
	
	i=atoi(lr_eval_string("{LoginC}"));
		
		if(i>0)
		{
			lr_output_message("Launch_Page_Successful");
			lr_end_transaction("S02_WT_Login_T02_Login_Page", LR_PASS);
			
		}
		else
		{
		lr_output_message("Login_Page_Failed");			
		lr_end_transaction("S02_WT_Login_T02_Login_Page", LR_FAIL);
		}
	
	
	
	/* Signoff */
	
	lr_think_time(thinktime);
	
	lr_start_transaction("S02_WT_Login_T03_Logoff_Page");


	web_reg_find("SaveCount=Logoff",
		"Text/IC=Username",
		LAST);

	web_url("SignOff Button", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

i=atoi(lr_eval_string("{Logoff}"));
		
		if(i>0)
		{
			lr_output_message("Logoff_Page_Successful");
			lr_end_transaction("S02_WT_Login_T03_Logoff_Page", LR_PASS);
			
		}
		else
		{
		lr_output_message("Logoff_Page_Failed");			
		lr_end_transaction("S02_WT_Login_T03_Logoff_Page", LR_FAIL);
		}
	

	

	return 0;
}