vuser_end()
{
	
	/* Sign Off */
	
	tName = "11.Exit";
	lr_start_transaction(tName);
	
	status=web_url("SignOff Button", 
		"URL={host}/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={host}/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	end_transaction(tName, status);
	
	return 0;
}
