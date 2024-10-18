	{skeleton
		{bone "basis"
			{matrix34
				1  0  0
				0 -1  0
				0  0  1
				0  0  0
			}
			{bone "foresight"
				{Orientation
					0	0	1
					0	1	0
					-1	0	0
				}
			}
		}
	}
	{able "-select"}

	{simulation {able 1} {state 1}}
	{constrain none}
	{obstacleID "nothing"}
	{collider "none"}
	{props "steel" "cw_cumulative_jetthrower"}
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
	 {extender "inventory"
		{box
			{Size 2 2}
			{weight 1}
		}
	}
	(define "piercing"
		{Weaponry
			{place "cm_weapon_jet"	;must be first
				{weapon "cm_weapon_jet" filling "cm_jet common %piercing ammo" 1}
				{foresight "foresight"}
				{gunner "driver"}
				{charger "driver"}
				{basic}
			}
		}
	)
