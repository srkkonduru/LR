	
	Action()
{

lr_start_transaction("WB_BLZ_T01");

web_service_call( "StepName=getBank_101",
		"SOAPMethod=BLZService|BLZServiceSOAP11port_http|getBank",
		"ResponseParam=response",
		"Service=BLZService",
		"ExpectedResponse=SoapResult",
		"Snapshot=t1639373882.inf",
		BEGIN_ARGUMENTS,
		"blz={blz_Num}",
		END_ARGUMENTS,
		BEGIN_RESULT,
		END_RESULT,
		LAST);
lr_end_transaction("WB_BLZ_T01", LR_AUTO);



	return 0;
}
