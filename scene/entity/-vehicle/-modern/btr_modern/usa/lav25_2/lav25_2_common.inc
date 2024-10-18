
	(include "/properties/armoredcar_amph.ext")
	(include "/properties/shadow/tank.inc"  scale(1.0))
	(include "/properties/selection/vehicle.inc"  scale(1.0))
	{props "vehicle" "armored_car_M" "tank" "turret" "wheeled" "with_gun" "vision_lev03"  "amphibia" "8_wheels" "lav25" "lav25_2" "with_open_zpu"}
	{targetClass "armoredcar" "ap fg bullet"}
	{PatherID "amphibia"}
        {extension "crew.ext"}

	("armor_light_btr" turret(14 10 10 8) body(10 9 9 7))	

	{extender "inventory"
			{weapon "mgun"
				{mask "weapon mgun"}
			}
		{box
			{item "ammo 762Nato" 1000}
			{item "m240" filled {user "mgun"}}
			{item "repair_kit" 1}
			{item "netting_kit" 3}
			;{item "ammo smoke_shtora" 8}	
		}
	}
	{Weaponry
		{place "mgun"
			{type "mgun_aa"}
			{gunner "gunner2"}
			{charger "gunner2"}
			{LinkBone "mgun"}
			{LinkAnimation "off"}
			{foresight "foresight4"}
			{basic}
			("CW_stab_no_stabiliser")
		}
		{place "mgun17"			
			{type "mgun_right"}
			{weapon "4xsmokegun_bredly" filling "smoke_shtora ammo" 4}
			{gunner "driver"}
			{charger "driver"}
			{foresight "foresight21"}
			{barrels 4}
			
		}
		{place "mgun18"		
			{type "mgun_left"}
			{weapon "4xsmokegun_bredly" filling "smoke_shtora ammo" 4}
			{gunner "driver"}
			{charger "driver"}
			{foresight "foresight20"}
			{barrels 4}
			
		}
	}
	{sensor
		{visor "driver"
			{bone "visor1"}
			{vision "tank_driver"}
		}
		{visor "top"
			{vision "vehicle_top_mgun"} 
			{bone "mgun"}
		}
	}	
	("wheel" args "wheelright1")
	("wheel" args "wheelleft1")
	("wheel" args "wheelright2")
	("wheel" args "wheelleft2")
	("wheel" args "wheelright3")
	("wheel" args "wheelleft3")
	("wheel" args "wheelright4")
	("wheel" args "wheelleft4")
	{mass 12880}
	{Chassis
		("car_trace" fx("tracewheel02") step(0.09) wheell("wlf") wheelr("wrf") bonel("FXtraceL1") boner("FXtraceR1"))
		("car_trace" fx("tracewheel02") step(0.09) wheell("wlr") wheelr("wrr") bonel("FXtraceL2") boner("FXtraceR2"))
		("CW_wheels"
			Mass(12.8)
			Turnradius(8.9)
			Power(275)
			Realspeed(100)
			Gamespeed(55) 
			Range(660)
			Fuelvolume(300)
		)
	}
	{props "cwfs_fuel_300"}

	("CW_amphibia" Waterline(1.6) )
	("two_headlights")
	{Extension "lav25_2.mdl"}
	("missile_aimpoint_trucksize")
	{props "ecm_station_usa"}
	("cwts_buksir")

