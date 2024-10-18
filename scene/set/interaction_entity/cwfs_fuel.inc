
(define "remove_fuel_cap"
	{tags remove "cwfs_maxfuel_0"}
	{tags remove "cwfs_maxfuel_10"}
	{tags remove "cwfs_maxfuel_15"}
	{tags remove "cwfs_maxfuel_20"}
	{tags remove "cwfs_maxfuel_30"}
	{tags remove "cwfs_maxfuel_40"}
	{tags remove "cwfs_maxfuel_50"}
	{tags remove "cwfs_maxfuel_60"}
	{tags remove "cwfs_maxfuel_70"}
	{tags remove "cwfs_maxfuel_80"}
	{tags remove "cwfs_maxfuel_100"}
	{tags remove "cwfs_maxfuel_150"}
	{tags remove "cwfs_maxfuel_200"}
	{tags remove "cwfs_maxfuel_300"}
	{tags remove "cwfs_maxfuel_400"}
	{tags remove "cwfs_maxfuel_500"}
	{tags remove "cwfs_maxfuel_600"}
	{tags remove "cwfs_maxfuel_700"}
	{tags remove "cwfs_maxfuel_800"}
	{tags remove "cwfs_maxfuel_1000"}
	{tags remove "cwfs_maxfuel_1500"}
	{tags remove "cwfs_maxfuel_2000"}
	{tags remove "cwfs_maxfuel_3000"}
	{tags remove "cwfs_maxfuel_4000"}
	{tags remove "cwfs_maxfuel_5000"}
	{tags remove "cwfs_maxfuel_6000"}
	{tags remove "cwfs_maxfuel_7000"}
	{tags remove "cwfs_maxfuel_8000"}
	{tags remove "cwfs_maxfuel_10k"}
	{tags remove "cwfs_maxfuel_15k"}
	{tags remove "cwfs_maxfuel_20k"}
	{tags remove "cwfs_maxfuel_30k"}
	{tags remove "cwfs_maxfuel"}
)
(define "remove_fuel_tag"
	{tags remove "cwfs_fuel_0"}
	{tags remove "cwfs_fuel_10"}
	{tags remove "cwfs_fuel_15"}
	{tags remove "cwfs_fuel_20"}
	{tags remove "cwfs_fuel_30"}
	{tags remove "cwfs_fuel_40"}
	{tags remove "cwfs_fuel_50"}
	{tags remove "cwfs_fuel_60"}
	{tags remove "cwfs_fuel_70"}
	{tags remove "cwfs_fuel_80"}
	{tags remove "cwfs_fuel_100"}
	{tags remove "cwfs_fuel_150"}
	{tags remove "cwfs_fuel_200"}
	{tags remove "cwfs_fuel_300"}
	{tags remove "cwfs_fuel_400"}
	{tags remove "cwfs_fuel_500"}
	{tags remove "cwfs_fuel_600"}
	{tags remove "cwfs_fuel_700"}
	{tags remove "cwfs_fuel_800"}
	{tags remove "cwfs_fuel_1000"}
	{tags remove "cwfs_fuel_1500"}
	{tags remove "cwfs_fuel_2000"}
	{tags remove "cwfs_fuel_3000"}
	{tags remove "cwfs_fuel_4000"}
	{tags remove "cwfs_fuel_5000"}
	{tags remove "cwfs_fuel_6000"}
	{tags remove "cwfs_fuel_7000"}
	{tags remove "cwfs_fuel_8000"}
	{tags remove "cwfs_fuel_10k"}
	{tags remove "cwfs_fuel_15k"}
	{tags remove "cwfs_fuel_20k"}
	{tags remove "cwfs_fuel_30k"}
)
(define "set_new_cap"
	{if rand 0.5
		{if rand 0.5 {tags add "cwfs_maxfuel_%p10"}{tags add "cwfs_maxfuel"}
		else {tags add "cwfs_maxfuel_%p25"}{tags add "cwfs_maxfuel"}
		}
	else
		{if rand 0.5 {tags add "cwfs_maxfuel_%p50"}{tags add "cwfs_maxfuel"}
		else {tags add "cwfs_maxfuel_%p75"}{tags add "cwfs_maxfuel"}
		}
	}
)
{"cwfs_fuel"
	{on spawn ("remove_fuel_tag")}
	{on "update_lights"
	  {if not tagged "cwfs_set_fuel"
		{tags add "cwfs_check_fuel"}
	  }
	}
	{on "remove_fuel_tag" ("remove_fuel_tag")}
	{on repair
		{delay 0.1
			{if not work "fuel_tank_internal_a"
			else  not work "fuel_tank_internal_b"
			else  not work "fuel_tank_internal_c"
			else  not work "fuel_tank_internal_d"
			else  not work "fuel_tank_external_a"
			else  not work "fuel_tank_external_b"
			else  not work "fuel_tank_external_c"
			else  not work "fuel_tank_external_d"
			else ("remove_fuel_cap")
			}
		}
	}
}

;{"cwfs_fuel_800 cwfs_extfuel_1500"
;	{on pierce
;		{if component "fuel_tank_internal"
;			("set_new_cap" p10(200) p25(300) p50(500) p75(600))
;		else component "fuel_tank_external"
;			("set_new_cap" p10(800) p25(1000) p50(1000) p75(1500))
;		}
;	}
;}
;====================================
(define "cwfs_fuelpreset_simple"
	{"cwfs_fuel_%fuel"
		{on pierce
			{if component "fuel_tank_internal"
				("set_new_cap" p10(%p10) p25(%p25) p50(%p50) p75(%p75))
			}
		}
	}
)
("cwfs_fuelpreset_simple" fuel(10) p10(0) p25(0) p50(10) p75(10))
("cwfs_fuelpreset_simple" fuel(15) p10(0) p25(0) p50(10) p75(10))
("cwfs_fuelpreset_simple" fuel(20) p10(0) p25(10) p50(10) p75(15))
("cwfs_fuelpreset_simple" fuel(30) p10(0) p25(10) p50(15) p75(20))
("cwfs_fuelpreset_simple" fuel(40) p10(0) p25(10) p50(20) p75(30))
("cwfs_fuelpreset_simple" fuel(50) p10(10) p25(15) p50(30) p75(40))
("cwfs_fuelpreset_simple" fuel(60) p10(10) p25(15) p50(30) p75(50))
("cwfs_fuelpreset_simple" fuel(70) p10(10) p25(20) p50(40) p75(50))
("cwfs_fuelpreset_simple" fuel(80) p10(10) p25(20) p50(40) p75(60))
("cwfs_fuelpreset_simple" fuel(100) p10(10) p25(30) p50(50) p75(80))
("cwfs_fuelpreset_simple" fuel(150) p10(15) p25(40) p50(80) p75(100))
("cwfs_fuelpreset_simple" fuel(200) p10(20) p25(50) p50(100) p75(150))
("cwfs_fuelpreset_simple" fuel(300) p10(30) p25(80) p50(150) p75(200))
("cwfs_fuelpreset_simple" fuel(400) p10(40) p25(100) p50(200) p75(300))
("cwfs_fuelpreset_simple" fuel(500) p10(50) p25(150) p50(300) p75(400))
("cwfs_fuelpreset_simple" fuel(600) p10(60) p25(150) p50(300) p75(500))
("cwfs_fuelpreset_simple" fuel(700) p10(70) p25(200) p50(400) p75(500))
("cwfs_fuelpreset_simple" fuel(800) p10(80) p25(200) p50(400) p75(600))
("cwfs_fuelpreset_simple" fuel(1000) p10(100) p25(300) p50(500) p75(800))
("cwfs_fuelpreset_simple" fuel(1500) p10(150) p25(400) p50(800) p75(1000))
("cwfs_fuelpreset_simple" fuel(2000) p10(200) p25(500) p50(1000) p75(1500))
("cwfs_fuelpreset_simple" fuel(3000) p10(300) p25(800) p50(1500) p75(2000))
("cwfs_fuelpreset_simple" fuel(4000) p10(400) p25(1000) p50(2000) p75(3000))
("cwfs_fuelpreset_simple" fuel(5000) p10(500) p25(1500) p50(3000) p75(4000))
("cwfs_fuelpreset_simple" fuel(6000) p10(600) p25(1500) p50(3000) p75(5000))
("cwfs_fuelpreset_simple" fuel(7000) p10(700) p25(2000) p50(4000) p75(5000))
("cwfs_fuelpreset_simple" fuel(8000) p10(800) p25(2000) p50(4000) p75(6000))
("cwfs_fuelpreset_simple" fuel(10k) p10(1000) p25(3000) p50(5000) p75(8000))
("cwfs_fuelpreset_simple" fuel(15k) p10(1500) p25(4000) p50(8000) p75(10k))
("cwfs_fuelpreset_simple" fuel(20k) p10(2000) p25(5000) p50(10k) p75(15k))
("cwfs_fuelpreset_simple" fuel(30k) p10(3000) p25(8000) p50(15k) p75(20k))
;============================================
(define "cwfs_fuelpreset_extonly"
	{"cwfs_ext_only cwfs_extfuel_%fuel"
		{on pierce
			{if component "fuel_tank_external"
				("set_new_cap" p10(%p10) p25(%p25) p50(%p50) p75(%p75))
			}
		}
	}
)
("cwfs_fuelpreset_extonly" fuel(80) p10(10) p25(20) p50(40) p75(60))
("cwfs_fuelpreset_extonly" fuel(150) p10(15) p25(40) p50(80) p75(100))
("cwfs_fuelpreset_extonly" fuel(200) p10(20) p25(50) p50(100) p75(150))
("cwfs_fuelpreset_extonly" fuel(300) p10(30) p25(80) p50(150) p75(200))
("cwfs_fuelpreset_extonly" fuel(400) p10(40) p25(100) p50(200) p75(300))
("cwfs_fuelpreset_extonly" fuel(1000) p10(100) p25(300) p50(500) p75(800))
;============================================

;int and ext fuel should be rounded DOWN
;T-80 - 1100 int 700 ext (400 in barrels are counted)
{"cwfs_fuel_1000 cwfs_extfuel_2000"
	{on pierce
		{if component "fuel_tank_external"
			("set_new_cap" p10(1000) p25(1000) p50(1500) p75(1500))
		}
	}
}
;T-14-15 - 1000 int 615 ext (no barrels)
{"cwfs_fuel_1000 cwfs_extfuel_1500"
	{on pierce
		{if component "fuel_tank_external"
			("set_new_cap" p10(1000) p25(1000) p50(1000) p75(1500))
		}
	}
}
;Merkava 4 - 1400 total - approx 800 int 600 ext
{"cwfs_fuel_800 cwfs_extfuel_1000"
	{on pierce
		{if component "fuel_tank_external"
			("set_new_cap" p10(800) p25(800) p50(1000) p75(1000))
		}
	}
}
;T-72-90 - 705 int 495 ext (400 in barrels are counted)
;T-64BM - 730 int 540 ext (400 in barrels are counted)
;T-64B - 738 int 355 ext (400 in barrels are counted) rounded to 1500
;ZTZ-99 - 745 int 500 ext (400 in barrels are counted) rounded to 1500
{"cwfs_fuel_700 cwfs_extfuel_1500"
	{on pierce
		{if component "fuel_tank_external"
			("set_new_cap" p10(800) p25(1000) p50(1000) p75(1500))
		}
	}
}
;ZTZ-96B - 675 int 400 ext (no barrels)
{"cwfs_fuel_600 cwfs_extfuel_1000"
	{on pierce
		{if component "fuel_tank_external"
			("set_new_cap" p10(700) p25(700) p50(800) p75(800))
		}
	}
}
;T-62 - 675 int 285 ext (400 in barrels are NOT counted because not integrated in fuel system)
{"cwfs_fuel_600 cwfs_extfuel_800"
	{on pierce
		{if component "fuel_tank_external"
			("set_new_cap" p10(700) p25(700) p50(800) p75(800))
		}
	}
}
;BM Oplot - 575 int 570 ext (400 in barrels are counted)
{"cwfs_fuel_600 cwfs_extfuel_1500"
	{on pierce
		{if component "fuel_tank_external"
			("set_new_cap" p10(600) p25(800) p50(1000) p75(1500))
		}
	}
}
;T-55 - 580 int 320 ext (400 in barrels are NOT counted because not integrated in fuel system)
{"cwfs_fuel_500 cwfs_extfuel_800"
	{on pierce
		{if component "fuel_tank_external"
			("set_new_cap" p10(600) p25(600) p50(700) p75(800))
		}
	}
}
;Leopard 2 - 500 int 700 ext
{"cwfs_fuel_500 cwfs_extfuel_1000"
	{on pierce
		{if component "fuel_tank_external"
			("set_new_cap" p10(500) p25(600) p50(800) p75(1000))
		}
	}
}
;Bradley M2 - 662 total, approx 400 int 262 ext
{"cwfs_fuel_400 cwfs_extfuel_600"
	{on pierce
		{if component "fuel_tank_external"
			("set_new_cap" p10(400) p25(500) p50(500) p75(600))
		}
	}
}
;2S7 - 1280 total - approx 305 int 975 ext
{"cwfs_fuel_300 cwfs_extfuel_800"
	{on pierce
		{if component "fuel_tank_external"
			("set_new_cap" p10(400) p25(500) p50(700) p75(1000))
		}
	}
}
;BMP-1-2 - 338 int 122 ext
{"cwfs_fuel_300 cwfs_extfuel_400"
	{on pierce
		{if component "fuel_tank_external"
			("set_new_cap" p10(300) p25(400) p50(400) p75(400))
		}
	}
}