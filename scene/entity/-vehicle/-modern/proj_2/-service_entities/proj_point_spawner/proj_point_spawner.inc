actor


{simulation {able 1} {disableLinked 1}}
{constrain none}
{props "nocover"}
{lodclass "stuff_small"}
{simulatorId "grenade"}

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
	{collider "proj_target"}

	{Extension "proj_point_spawner.mdl"}
	{props "-steel" "-wood"}
	{obstacleID "nothing"}
	{extender "stuff"
		{item "empty_stuff"}
	}

