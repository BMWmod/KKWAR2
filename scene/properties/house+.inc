;SDL
;CW house additions
(define "house_emit"
	{skeleton
;		{bone "basis"			;у некоторых зданий базисы зеркальные, и эмит их выворачивает наизнанку
			{bone "emit%n"
				{Position (* 20 %x) (* 20 %y) 0}
				{visibility 0}
			}
;		}
	}
)
(define "house_emit_reversed"
	{skeleton
;		{bone "basis"
			{bone "emit%n"
				{matrix34 
				-1	0	0 
				0	-1	0 
				0	0	1  
				(* 20 %x) (* 20 %y) 0
				}
				{visibility 0}
			}
;		}
	}
)
(define "volume_bottom_floor"
	{volume "bottom_floor"
		{able {visible 0}{Obstacle 0}}
	}
	{"volumes"
		{"bottom_floor"
			{box (* 19.99 %x) (* 19.99 %y) 30}
			{bone "basis"}
			{Position (* 20 %shiftx) (* -20 %shifty) 0}
		}
	}
)
(define "house_main_obstacle"
	("volume_bottom_floor" x(%x) y(%y) shiftx(%shiftx) shifty(%shifty))
	{obstacle "obstacle"
		{obb2
			{center (* 20 %shiftx) (* 20 %shifty)}
			{extent (* 10 %x) (* 10 %y)}
			{axis -1 0}
		}
		{rotate}
	}
)
(define "house_add_obstacle"
	{obstacle "obstacle%n"
		{obb2
			{center (* 20 %shiftx) (* 20 %shifty)}
			{extent (* 10 %x) (* 10 %y)}
			{axis -1 0}
		}
		{rotate}
	}
)
(define "house_add_obstacle_angled"
	{obstacle "obstacle%n"
		{obb2
			{center (* 20 %shiftx) (* 20 %shifty)}
			{extent (* 10 %x) (* 10 %y)}
			{axis %cos %sin}
		}
		{rotate}
	}
)
(define "house_add_obstacle_circle"
	{obstacle "obstacle%n"
		{Circle2
			{center (* 20 %shiftx) (* 20 %shifty)}
			{radius (* 20 %r)}
		}
		{rotate}
	}
)