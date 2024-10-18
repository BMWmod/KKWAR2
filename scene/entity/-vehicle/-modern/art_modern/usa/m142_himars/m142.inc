;Created by Pheonix
	(include "/properties/car.ext")
	(include "/properties/shadow/tank.inc"  scale(1.0))
	(include "/properties/selection/vehicle.inc"  scale(1.1))
	{collider "truck"}
	{props "vehicle" "car" "truck" "turret" "with_gun" "wheeled" "6_wheels" "vision_lev03" "armored_glass" "cw_artillery" "mtvr" "skill_override_car"}
	{targetClass "armoredcar"}
	{able "emit_on_attack"}
	("armor_car_STANAG3_custom" mrap(18) mrap_val(90))
	
	(define "board_animation"
		{boarder
			{anm "%place"
				{forward	{begin	"%board_begin"} {end "%board_end"} {base "%base"}}
				{reverse 	{end	"%board_begin" -1} {base "%base" 1}}
			}
		}
	)
	

	{brain
		{properties
			{fire_mode hold}	;Это я нашел у нашей гаубицы Б4.
		}
	}
	
	(define "crew_gun"
		("crew_human" place(driver)		bone(driver)	door(emit1) animation(driver))
		("crew_human" place(gunner)		bone(gunner)		door(emit2) animation(gunner))
	)
	("crew_gun")
	("board_animation"
		place(driver)
		board_begin(board_big-midcar_driver)
		board_end(seat_driver_car)
		base(doorleft)
	)
	("board_animation"
		place(gunner)
		board_begin(board_big-midcar)
		board_end(seat_passenger)
		base(doorright)
	)
	{Volume "body"	   {tags "body"}		{component "body"}		{thickness 15}}
	{Volume "cabin"	   {tags "cabin"}		{component "cabin"}		{thickness 10}}
	{Volume "engine"   {tags "body"}		{component "engine"}	{thickness 5}}
	{Volume "window1"	{thickness 0.1}{component "cabin"}{able {visible 0}{window}{obstacle 0}}}
	{Volume "window2"	{thickness 0.1}{component "cabin"}{able {visible 0}{window}{obstacle 0}}}
	{Volume "glass"	{thickness 0.1}{component "cabin"}{able {visible 0}{window}{obstacle 0}}}
	{Volume "inventory"		{tags "explosive"}							{thickness 0.2}}
	("wheel" args "wheelright1")("wheel" args "wheelleft1")
	("wheel" args "wheelright2")("wheel" args "wheelleft2")
	("wheel" args "wheelright3")("wheel" args "wheelleft3")
	{mass 16250}
	{Chassis
		("CW_wheels"
			Mass(16.2)
			Turnradius(14)
			Power(425)
			Realspeed(94)
			Gamespeed(52) 
			Range(483)
			Fuelvolume(295)
		)
		("car_trace" fx("tracewheel03") step(0.08) wheell("wlf") wheelr("wrf") bonel("FXtraceL1") boner("FXtraceR1"))
		("car_trace" fx("tracewheel03") step(0.08) wheell("wlr") wheelr("wrr") bonel("FXtraceL2") boner("FXtraceR2"))
		("car_trace" fx("tracewheel03") step(0.08) wheell("wlr") wheelr("wrr") bonel("FXtraceL3") boner("FXtraceR3"))
		
	}
	{props "cwfs_fuel_200"}
	
