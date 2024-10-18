actor
	{brain "actor"
		{state "animal"}
	}
{able "-minimap"}
{placer {crew}}
{collider "construction"}
{obstacleID "construction"}
{mass 300}
{armor
	{setting "body"
		{health_reducing
			{pierce
				{koef 0}
			}
			{blast
				{koef 0}
			}
		}
		{threshold
			{blast
				{value 15}
			}
		}
		{durability
			{blast
				{value 50}
			}
			{pierce
				{value 1400}
			}
		}
		{fragment_pass_threshold 1}
	}
}
{lodclass "decor_medium"}
{groupmesh}
	
	
	
	
	
	
	
	
	
	{props "unbreakable" "vehicle" "no_destroyed_stamp"}
	{Volume "attach1"
		{Tags  "attach" "x"}
		{able clear {touch 1}}
	}
	{Volume "attach2"
		{Tags  "attach" "x"}
		{able clear {touch 1}}
	}
	{placer
		{place "x" {NoCollect}}
	}

	{boarder
		{door "bottom" {queue} {chain "up"} {auto_release_time 1.5}}
		{door "top" {queue} {chain "down"} {auto_release_time 1.5}}
		{node "node01"}
		{node "node02"}
		{node "node03"}

		{anm "up"
			{forward {speed 1.2} {loop "stand_upstairs"} {fix_orientation}}
		}
		{anm "down"
			{forward {speed 1.2} {loop "stand_upstairs" -1} {fix_orientation}}
		}

		{link "bottom" "node01"	{anm "[fsm]"} {chain "up"}}
		{link "node01" "node02"	{anm "[fsm]"} {chain "up"}}
		{link "node02" "node03"	{anm "up"} {chain "up"}}
		{link "node03" "top"			{chain "up"}}
		{link "top" 			"x"					 {chain "up"}}
		
		{link "top"			"node03"			{anm "[fsm]"} {chain "down"}}
		{link "node03"	"node02"			{anm "down"}  {chain "down"}}
		{link "node02"	"node01"			{anm "[fsm]"}  {chain "down"}}
		{link "node01"	"bottom"			{anm "[fsm]"} {chain "down"}}
		{link "bottom"			"x"					 {chain "down"}}
	}

