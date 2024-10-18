	(include "/properties/car.ext")
	(include "/properties/shadow/tank.inc"  scale(1.0))
	(include "/properties/selection/vehicle.inc"  scale(1.1))
	{props "vehicle" "car" "truck" "tank" "wheeled" "turret_rotator" "vision_lev05" "8_wheels" "smerch_common" "-standart_netting" "long_netting" "cw_artillery" "skill_override_car"}
	{collider "tank.medium"}
	{PatherID  "tank"}
	{able "emit_on_attack"}
	("armor_car_truck")
	{extender "enumerator"}

	{Volume "gun"
		{thickness 3}
		{component "turret"}
	}
	("wheel" args "wheelright1")
	("wheel" args "wheelleft1")
	("wheel" args "wheelright2")
	("wheel" args "wheelleft2")
	("wheel" args "wheelright3")
	("wheel" args "wheelleft3")
	("wheel" args "wheelright4")
	("wheel" args "wheelleft4")
{boarder
	{anm "driver"
		{forward	{begin	"board_big-highcar_driver"} {end "seat_driver_car"} {base "doorleft"}}
		{reverse 	{end	"board_big-highcar_driver" -1} {base "doorleft" -1}}
	}
	{anm "commander1"
		{forward	{begin	"board_big-highcar_driver"} {end "seat_passenger"} {base "doorleft2"}}
		{reverse 	{end	"board_big-highcar_driver" -1} {base "doorleft2" -1}}
	}
	{anm "commander"
		{forward	{begin	"board_higharmor"} {end "seat_driver_car"} {base "doorleft3"}}
		{reverse 	{end	"emit_body"} {base "doorleft3" -1}}
	}
	{anm "gunner"
		{forward	{begin	"board_higharmor"} {end "seat_driver_car"} {base "doorright"}}
		{reverse 	{end	"emit_body"} {base "doorright" -1}}
	}
	{link "driver" "Seat01"}
	{link "gunner" "Seat02"}
}
{boarder
	{door "emit1"}
	{link "emit1" "driver" {anm "driver"} {forward putoff} {reverse puton}}
}

(define "crew_human_visible"
	{placer
		{place "%place" {LinkBone "%place"} {group "%group"} {visor "%visor"}}
	}
	{boarder
		{door "%door"}
		{link "%door" "%place" {anm "%animation"} {forward putoff} {reverse puton}}
	}
)
;это мехвод. В развернутом состоянии неактивен, превращается в пассажира. В неразвернутом ведет.
("crew_human_visible" place(driver)			door(emit1) group(crew)		animation(driver)	    visor(driver))
("crew_human_visible" place(Seat01)		door(emit1) group(crew)		animation(driver)	    visor(driver))
;Это стрелок. В развернутом стреляет, в неразвернутом - пассажир.
("crew_human_visible" place(gunner)		door(emit2) group(crew)	    animation(gunner)	    visor(main))
("crew_human_visible" place(Seat02)		door(emit2) group(crew)	    animation(gunner)	    visor(main))
;Остальные.
("crew_human_visible" place(commander)		door(emit4) group(crew)	    animation(commander)	    visor(main))
("crew_human_visible" place(commander1)	door(emit3) group(crew)	    animation(commander1)	    visor(main))

	{extender "inventory"
		{box
			{Size 9 5}
			{weight 3000}
		}
	}
	{brain
		{properties
			{fire_mode hold}	;Это я нашел у нашей гаубицы Б4.
		}
	}
	{extender "cannon"
		{animation
			{move "" ""}
			{reload "" ""}
			{aim "" ""}
		}
		{animation
			{switch close}
		}
		{driver {workers "driver"}}
		{move {workers "driver" "Seat02"} {obstacle "close"}}
		{attack {workers "Seat01" "gunner"} {obstacle "open"}}
		{rotate_ik_Limit 0}
	}

	{mass 43700}	
	{Chassis
		("car_trace" fx("tracewheel03b") step(0.3) wheell("wlf") wheelr("wrf") bonel("FXtraceL1") boner("FXtraceR1"))
		("car_trace" fx("tracewheel03b") step(0.3) wheell("wlr") wheelr("wrr") bonel("FXtraceL3") boner("FXtraceR3"))
		("car_trace" fx("tracewheel03b") step(0.3) wheell("wlf1") wheelr("wrf1") bonel("FXtraceL2") boner("FXtraceR2"))
		("car_trace" fx("tracewheel03b") step(0.3) wheell("wlr1") wheelr("wrr1") bonel("FXtraceL4") boner("FXtraceR4"))
		("CW_wheels"
			Mass(43.7)
			Turnradius(13.3)
			Power(525)
			Realspeed(60)
			Gamespeed(39) 
			Range(850)
			Fuelvolume(840)
		)
	}
	{props "cwfs_fuel_800"}

	("two_headlights")

