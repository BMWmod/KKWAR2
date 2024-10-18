	{Extension "flagstaff.mdl"}
	{props "flag" "steel" "flag_slave" "vehicle" "mp_flag"}
	{obstacleID "unbreakable"}
	{Volume "body"
		{Tags  "body"}
		{Thickness 50}
		{able clear {touch 1}}
	}
	{autooperatable 1}
       {placer
          {crew 0}
       }
	{brain "vehicle"
		{state "vehicle"}
		{const "crush/min_danger_zone_time" 	1}
		{const "crush/min_danger_zone_length"	1}
	}
	{Weaponry
		{ManualAccuracy 1.0}	;теперь это обязательный блок
	}
	{PatherID  "armored"}
	
	{targetSelector "tank"}
	{extender "inventory"
		{box
		}
	}
{PatherID  "railway"}
(define "locomotion"
	{MaxSpeed	25	}		; максимальная скорость, kmph
	{StartTime	10	}		; время разгона до макс. скорости с 0, seconds
	{BrakeTime	5	}		; время торможения с макс. скорости до 0, seconds
	{StopTime	10	}		; время остановки после отключения двигателя с макс. скорости до 0, seconds
)
{Chassis "railway"
	{ignorePatherBounds}
	{speed
		{Slow	10	}	; km/h
		{Normal	17	}
		{Fast	30	}
	}
}
{Chassis
		{Locomotion ("locomotion")
			{MaxSpeed	20	}
			{StartTime	3	}
			{BrakeTime	3	}
		}
	}
	{component "body"
	{RepairTime 25}
}
	
; causes quant_ge crush when trying to rotate
;	{Weaponry
;		{place "binocular"
;			{weapon "binocular" filled}
;			{gunner "driver"}
;			{foresight "foresight"}
;		}
;	}