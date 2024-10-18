{"muzzle_zenite"
	{on spawn
		{add_view	"flash_cannon_small"		"flashbarrel1"			"Foresight1"}
	}
	{on fire "gun"
        {spawn "tank_canon_fire_verysmall" 		"Foresight1" x}
	}
}

{"muzzle_minimum"
	{on spawn
		{add_view	"flash_cannon_small"		"flashbarrel1"			"Foresight1"}
	}
	{on fire "gun"
       	{spawn "dust_shot_small" 				"basis"}
        {spawn "tank_canon_fire_verysmall" 		"Foresight1" x}
	}
}	

{"muzzle_small"
	{on spawn
		{add_view	"flash_cannon_small"		"flashbarrel1"			"Foresight1"}
	}
	{on fire "gun"
       	{spawn "dust_shot_small" 				"basis"}
        {spawn "tank_canon_fire_small" 			"Foresight1" x}
	}
}	
	
{"muzzle_medium"
	{on spawn                                                                                            
		{add_view	"flash_cannon_medium"		"flashbarrel1"			"Foresight1"}
		{add_view	"flash_cannon_medium"		"flashbarrel2"			"Foresight2"}
	}
	{on fire "gun"
       	{spawn "dust_shot_norm" 				"basis"}
        {spawn "tank_canon_fire_medium" 		"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.5 bone 		"Foresight1"}
	}
}
	
{"muzzle_large"
	{on spawn                                                                                            
		{add_view	"flash_cannon_medium"		"flashbarrel1"			"Foresight1"}
		{add_view	"flash_cannon_medium"		"flashbarrel2"			"Foresight2"}
	}
	{on fire "gun"
      	{spawn "dust_shot_big" 					"basis"}
      	{spawn "tank_canon_fire_large" 			"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.5 bone 		"Foresight1"}
	}
}
	
{"muzzle_maximum"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel1"			"Foresight1"}
		{add_view	"flash_cannon_medium"		"flashbarrel2"			"Foresight2"}
	}
	{on fire "gun"
	{spawn "dust_shot_big" 						"basis"}
        {spawn "tank_canon_fire_verylarge" 		"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.8 bone 		"Foresight1"}
	}
}