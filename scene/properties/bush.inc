game_entity
	(include "seasons.inc")
	{volume "crown"
		{Able {contact 0} {bullet 0} {obstacle 0} {touch 0} {overlap 1}}
;		{Able {contact 0} {bullet 0} {throwing 0} {obstacle 0} {touch 0} {overlap 1}}	;disabled in MOW2
	}
	{volume "crown1"
		{Able {contact 0} {bullet 0} {obstacle 0} {touch 0} {overlap 1}}
;		{Able {contact 0} {bullet 0} {throwing 0} {obstacle 0} {touch 0} {overlap 1}}	;disabled in MOW2
	}
	{collider "bush"}
	{obstacleID "nothing"}
	{props "tree" "bush"}
	{volume defaultmaterial "wood"}
	{lodclass "decor_medium"}
