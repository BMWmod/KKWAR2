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
		{ManualAccuracy 1.0}	;������ ��� ������������ ����
	}
	{collider "bush"}

	{Extension "proj_point_acc.mdl"}
	{Volume "body" {able clear {contact} {bullet 0} {visible 1}  {select 0}} {Thickness 0.01} {component "body"}}
	{Volume "target" {able clear {contact} {bullet 1} {visible}  {select 0}} {Thickness 0.01} {component "body"}}
	{component "body"}	;�� ������� - �������� �� ������������
	{props "-steel" "-wood" "vis_proj_point" "proj_point_acc"}
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
