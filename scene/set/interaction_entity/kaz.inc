{"generic"
	{on contact overload
		{if not effector "kaz" {inherited}
		else
			{with_effector
				{if not tagged "kaz_working"
					{with_effector	{inherited}}
				}
			}
		}
	}
}