#### Update done : 2025-01-15
#### Work with DX11 Apex not DX12 , some fonction not work it's up to you to fix (esp work good / have no visible check)
#### Arguments lines if you want play DX11 : -anticheat_settings=SettingsDX11.json

	bool isVisable()
	{
		float cur_time = read<float>(GameAddress + 0x18BE180 + 0x10); //Global_vars

		float visible_time = read<float>(this->address + offsets::lastVisableTime);

		return visible_time > 0.0f && fabsf(visible_time - cur_time) < 0.1f;
	}
