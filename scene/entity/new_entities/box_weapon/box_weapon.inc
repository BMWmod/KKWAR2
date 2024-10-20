
    {Simulation {Able 1}}
	{PatherID "airborne"}
        {obstacleid "nothing"}
	{props "steel" "no_destroyed_stamp"}
	{props "inventory_box" "spread_items" "box_weapon_mp"}
	{Extension "box_weapon.mdl"}
	{ObstacleID "stuff"}
    {autooperatable 1}
       {placer
          {crew 0}
          {place "driver" remove}
       }
	{brain "vehicle"
		{state "vehicle"}
		{const "crush/min_danger_zone_time" 	1}
		{const "crush/min_danger_zone_length"	1}
	}
	{Weaponry
		{ManualAccuracy 1.0}	;теперь это обязательный блок
	}
	{targetSelector "none"}
	{collider "nothing"}
	{simulation {able 1}}
	{mass 100}

	{Volume "box01"
		{able {touch}}
	}
	{Chassis "track"
	{Locomotion
	   {MaxSpeed		0}
		{maxSpeedAtMaxTurn	0}
		{StartTime		0.001}
		{BrakeTime		0.001}
		{StopTime		0.001}
		{TurnTime		0.001}
		{TurnStart		0.001}
		{TurnRadius		0.001}
		{TurnStop		0.001}
		{Gears			0.12 1}
		{RearGears		1}
		{GearSwitchDelay	0.001}	
	}
	{FuelBag
		{volume 10 }	; liters
		{remain 0 }
		{rate 0.001}
		{fuel "fuel"}
	}
	{speed
		{Slow	0	}	; km/h
		{Normal	0	}
		{Fast	0	}
	}
}

