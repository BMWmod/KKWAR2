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
	{collider "human"}
	{Weaponry
		{ManualAccuracy 1.0}	;теперь это обязательный блок
	}

	{Extension "cw_bullet_target.mdl"}
	{Volume "body" {able clear} {Thickness 2.1} {component "body"}}
	{Volume "target_front" {able clear {visible} {select 0} {bullet 1}}  {Thickness 2.1} {component "body"}}
	{Volume "targ_for_missile" {able clear {visible} {select 0} {bullet 1}}  {Thickness 20.1} {component "body"}}
	;{Volume "contact" {able clear {contact 1} {overlap 1}}  {Thickness 2.1} {component "body"}}
	;{Volume "contact1" {able clear {contact 1} {overlap 1}}  {Thickness 2.1} {component "body"}}
	;{Volume "contact2" {able clear {contact 1} {overlap 1}}  {Thickness 2.1} {component "body"}}
	;{Volume "contact3" {able clear {contact 1} {overlap 1}}  {Thickness 2.1} {component "body"}}
	;{Volume "contact4" {able clear {contact 1} {overlap 1}}  {Thickness 2.1} {component "body"}}
	;{Volume "contact5" {able clear {contact 1} {overlap 1}}  {Thickness 2.1} {component "body"}}
	;{Volume "contact6" {able clear {contact 1} {overlap 1}}  {Thickness 2.1} {component "body"}}
	{component "body"}	;не удалять - отвечает за прицеливание
	{props "-steel" "-wood" "cw_bullet_target" "vis_proj_point"}
	{obstacleID "nothing"}
	{extender "stuff"
		{item "empty_stuff"}
	}
