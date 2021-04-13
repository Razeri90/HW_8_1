Delete()
{
	/* delete */

	tName = "07.Itinerary_one_ticket";
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
		"Referer={host}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
	
	end_transaction(tName, status);
	
	tName = "08.Delete_one_ticket";
	lr_start_transaction(tName);

    status=web_submit_data("itinerary.pl", 
		"Action={host}/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={host}/cgi-bin/itinerary.pl", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=flightID", "Value={FlightID_1}", ENDITEM,
		"Name=1", "Value=on", ENDITEM,
		"Name=.cgifields", "Value=1", ENDITEM,
		"Name=removeFlights.x", "Value=69", ENDITEM,
		"Name=removeFlights.y", "Value=8", ENDITEM,
		LAST);
	
	end_transaction(tName, status);
	
	return 0;
}
