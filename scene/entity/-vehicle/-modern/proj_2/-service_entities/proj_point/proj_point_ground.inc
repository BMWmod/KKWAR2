actor

{able "-select"}
{simulation {able 1} {disableLinked 1}}
{constrain none}
{props "nocover"}
{lodclass "stuff_small"}
{simulatorId "grenade"}
{body {proper body sensible} {permit body}}

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
	;{collider "projectile_target"}
     {collider "human"}
	{Extension "proj_point_ground.mdl"}
	{Volume "body" {able clear {contact}  {visible} {bullet} {select 0}} {Thickness 0.1} {component "body"}}
	{Volume "target" {able clear {visible} {select 0}} {Thickness 0.1} {component "body"}}
	{component "body"}	;не удалять - отвечает за прицеливание
	{props "-steel" "-wood" "proj_point" "vis_proj_point" "proj_point_ground"}
	{obstacleID "nothing"}
	{extender "stuff"
		{item "empty_stuff"}
	}
(define "proj_thick"
	{armor
		{setting "body"
			{thickness 10}
			{threshold  {blast {value 1000}}}	; 
			{durability {blast {value 1000}}}	; 
			{volumes "body*"}
		}
	}
)
