Create()
{
	/* flights */

	tName = "03.Search_FindFlight";
	lr_start_transaction(tName);

	status=web_url("Search Flights Button", 
		"URL={host}/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={host}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
	
	end_transaction(tName, status);
	
	tName = "04.Create_ticket";
	lr_start_transaction(tName);
	
	web_reg_save_param_ex(
    "ParamName=outboundF", 
    "LB/IC=\"outboundFlight\" value=\"",
    "RB/IC=\"",
    "Ordinal={Rnd2}",
	LAST);

	/* c1 ff */

	status=web_submit_data("reservations.pl", 
		"Action={host}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={host}/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={city1}", ENDITEM, 
		"Name=departDate", "Value={date1}", ENDITEM, 
		"Name=arrive", "Value={city2}", ENDITEM, 
		"Name=returnDate", "Value={date2}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value={pseatPref}", ENDITEM, 
		"Name=seatType", "Value={pseatType}", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM,  
		"Name=findFlights.x", "Value=63", ENDITEM, 
		"Name=findFlights.y", "Value=10", ENDITEM, 
		LAST);

	end_transaction(tName, status);

	/* c2 ff */	

	tName = "05.Create_ticket_part2";
	lr_start_transaction(tName);
	
	status=web_submit_data("reservations.pl_2", 
		"Action={host}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={host}/cgi-bin/reservations.pl", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={outboundF}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value={pseatType}", ENDITEM, 
		"Name=seatPref", "Value={pseatPref}", ENDITEM, 
		"Name=reserveFlights.x", "Value=30", ENDITEM, 
		"Name=reserveFlights.y", "Value=1", ENDITEM, 
		LAST);
	
	end_transaction(tName, status);

	/* c3 pd */
	
	tName = "06.Create_ticket_payments_detail";
	lr_start_transaction(tName);

	status=web_submit_data("reservations.pl_3", 
		"Action={host}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={host}/cgi-bin/reservations.pl", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value=Jojo", ENDITEM, 
		"Name=lastName", "Value=Bean", ENDITEM, 
		"Name=address1", "Value=", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=pass1", "Value=Jojo Bean", ENDITEM, 
		"Name=creditCard", "Value=", ENDITEM, 
		"Name=expDate", "Value=", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value={pseatType}", ENDITEM, 
		"Name=seatPref", "Value={pseatPref}", ENDITEM, 
		"Name=outboundFlight", "Value={outboundF}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		"Name=buyFlights.x", "Value=35", ENDITEM, 
		"Name=buyFlights.y", "Value=11", ENDITEM, 
		LAST);
	
	end_transaction(tName, status);

	return 0;
}