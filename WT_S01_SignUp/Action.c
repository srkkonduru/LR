Action()
{

	web_cleanup_cookies();
	
	web_cache_cleanup();
	
	web_cleanup_auto_headers();
	web_set_sockets_option("SSL_VERSION","AUTO");
	
	
	web_reg_find("Search=Body",
		"SaveCount=Launchpage",
		"Text/IC=Welcome to the Web Tours site",
		LAST);
	lr_start_transaction("WT_S01_SignUp_T01_LaunchPage");


	web_url("index.htm", 
		"URL=http://127.0.0.1:1080/webtours/index.htm", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("WT_S01_SignUp_T01_LaunchPage", LR_AUTO);
	
/*		web_image_check("web_image_check",
		"Alt=Login",
		LAST);

*/


	/* ************Click on Signup Now*********** */

	lr_think_time(10);
	
	

	web_reg_find("SaveCount=SignupPage",
		"Text/IC=First time registering?",
		LAST);
lr_start_transaction("WT_S01_SignUp_T02_SignUpPage");

	
	web_url("login.pl", 
		"URL=http://127.0.0.1:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/WebTours/home.html", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);
		
		lr_end_transaction("WT_S01_SignUp_T02_SignUpPage", LR_AUTO);
		
/*		web_image_check("web_image_check",
		"Src=/WebTours/images/button_next.gif",
		LAST);

*/
	/* Enter details nd click continue */

	lr_think_time(20);
	
	

	web_reg_find("SaveCount=success",
		"Text=Thank you",
		LAST);
	lr_start_transaction("WT_S01_SignUp_T03_customer_dtls_Page");


	web_submit_data("login.pl_2", 
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={U_name}", ENDITEM, 
		"Name=password", "Value={Password}", ENDITEM, 
		"Name=passwordConfirm", "Value={Password}", ENDITEM, 
		"Name=firstName", "Value={FirstName}", ENDITEM, 
		"Name=lastName", "Value={LastName}", ENDITEM, 
		"Name=address1", "Value={Address}", ENDITEM, 
		"Name=address2", "Value={State}", ENDITEM, 
		"Name=register.x", "Value=45", ENDITEM, 
		"Name=register.y", "Value=1", ENDITEM, 
		LAST);
	
	lr_end_transaction("WT_S01_SignUp_T03_customer_dtls_Page", LR_AUTO);
	


	/* click continue */

	lr_think_time(5);
	
	

	web_reg_find("SaveCount=welcome",
		"Text/IC=Welcome,",
		LAST);
	lr_start_transaction("WT_S01_SignUp_T04_dtls_After_continue_Page");


	web_url("button_next.gif", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);
	lr_end_transaction("WT_S01_SignUp_T04_dtls_After_continue_Page", LR_AUTO);


	/* signoff */

	lr_think_time(5);
	
	lr_start_transaction("WT_S01_SignUp_T05_SignOff_Page");


	web_reg_find("SaveCount=Signoff",
		"Text=Welcome to the Web Tours site.",
		LAST);

	web_url("SignOff Button", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);
	lr_end_transaction("WT_S01_SignUp_T05_SignOff_Page", LR_AUTO);
	
	

	
	//web_image_check("Logoff","alt=SignOff Button",LAST);


	return 0;
}