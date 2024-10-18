	(include "/properties/armoredcar_amph.ext")
	(include "/properties/shadow/tank.inc"  scale(1.0))
	(include "/properties/selection/vehicle.inc"  scale(1.0))
	{props "vehicle" "armored_car_M" "tank" "turret" "wheeled" "with_gun" "vision_lev03" "amphibia" "8_wheels" "btr90" "btr90_kom" "with_open_zpu" "3_barrels_smoke"}
	{PatherID "amphibia"}
	{targetClass "tank" "ap fg bullet"}
	{targetSelector "tank"}

	{volume "body1"
		{tags "body"}
		{component "body"}
	}
	{volume "body2"
		{tags "body"}
		{component "body"}
	}
	{volume "body3"
		{tags "body"}
		{component "body"}
	}
	{volume "body4"
		{tags "body"}
		{component "body"}
	}
	{volume "body5"
		{tags "body"}
		{thickness hollow 7}
		{component "body"}
	}
	{volume "part1"
		{tags "part"}
		{thickness hollow 3.0}
		{able clear {bullet 1}{CONTACT 0}{CONTACT_GROUND 0}{BLAST 1}{SELECT 0}{visible 0}}
	}
	{volume "part2"
		{tags "part"}
		{thickness hollow 3.0}
		{able clear {bullet 1}{CONTACT 0}{CONTACT_GROUND 0}{BLAST 1}{SELECT 0}{visible 0}}
	}
	{volume "part3"
		{tags "part"}
		{thickness hollow 3.0}
		{able clear {bullet 1}{CONTACT 0}{CONTACT_GROUND 0}{BLAST 1}{SELECT 0}{visible 0}}
	}
	{extension "crew.ext"}

	("armor_light_btr" turret(27 27 10 7) body(27 27 1 10))

	{extender "inventory"
		{weapon "mgun"
			{mask "weapon mgun"}
		}
		{box
			{item "ammo PKM_ammo" 400}
			{item "pkt" filled {user "mgun"}}
			{item "repair_kit" 1}
			{item "netting_kit" 3}
			;{item "ammo smoke_shtora" 6}	
		}
	}
	{Weaponry
		{place "mgun"
			{LinkBone "mgun"}
			{LinkAnimation "off"}
			{gunner "gunner2"}
			{charger "gunner2"}
			{basic}
			{foresight "foresight4"}
			("CW_stab_no_stabiliser")
		}
	}
	{sensor
		{visor "main"
			{vision "tank_gunner_optic_IR_2g"}
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


	{mass 20000}
	{Chassis
		("car_trace" fx("tracewheel02") step(0.09) wheell("wlf") wheelr("wrf") bonel("FXtraceL1") boner("FXtraceR1"))
		("car_trace" fx("tracewheel02") step(0.09) wheell("wlr") wheelr("wrr") bonel("FXtraceL2") boner("FXtraceR2"))
		{Locomotion ("CW_wheels_moveparam" 
				Mass(22)
				Turnradius(7.8)
				Power(510)
				Realspeed(100)
				Gamespeed(55) 
		)
		{RearGears		0.12 0.29 0.5 0.68 1}
		}
		("CW_fuelbag" Range(800) Fuelvolume(300))
	}
	{props "cwfs_fuel_300"}

	("CW_amphibia" Waterline(1.7) )
	("two_headlights")
	{Extension "btr90_kom.mdl"}
	("missile_aimpoint_trucksize")
	{props "ecm_station_rus"}
	("cwts_buksir")