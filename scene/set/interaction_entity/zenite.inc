;by Pheonix
{"zenite"
	{on "spawn"
		{if name "air"
		                            {volumes disable contact}
			 {if rand 0.2
				{delay 2
					{call "detonate"}
				}
			}
			 {if rand 0.4
				{delay 2.2
					{call "detonate"}
				}
			}
			 {if rand 0.5
				{delay 1.5
					{call "detonate"}
				}
			}
			 {if rand 0.6
				{delay 2.5
					{call "detonate"}
				}
			}
			 {if rand 0.8
				{delay 3
					{call "detonate"}
				}
			}
		}
		
	}
	{on "detonate"
		{fire radius 1.5 time 2 heating 6 effector}
		{stuff_detonate}
	}
	
}
