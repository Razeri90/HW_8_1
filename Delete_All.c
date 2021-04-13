Delete_All()
{
	/* delete all */
	
	tName = "09.Itinerary_all_ticket";
	lr_start_transaction(tName);
	
   	status=web_reg_save_param_ex(
    	"ParamName=FlightID", 
    	"LB/IC=name=\"flightID\" value=\"",
    	"RB/IC=\"  ",
    	"Ordinal=all",
	LAST);
	
	status=web_url("Itinerary Button", 
		"URL={host}/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);
	
	end_transaction(tName, status);
	
	tName = "10.Delete_all_ticket";
	lr_start_transaction(tName);
	
	status=web_submit_data("itinerary.pl", 
		"Action={host}/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={host}/cgi-bin/itinerary.pl", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=flightID", "Value={FlightID_1}", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=removeAllFlights.x", "Value=43", ENDITEM, 
		"Name=removeAllFlights.y", "Value=14", ENDITEM, 
		LAST);
	
	end_transaction(tName, status);
		
	return 0;
}