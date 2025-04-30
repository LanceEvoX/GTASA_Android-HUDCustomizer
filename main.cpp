#include <mod/amlmod.h>
#include <mod/logger.h>
#include <mod/config.h>



MYMODCFG(chzbrgr.hudcustomizer, HUD Customizer, 1.0, cheeseburger)
NEEDGAME(com.rockstargames.gtasa)
BEGIN_DEPLIST()
    ADD_DEPENDENCY_VER(net.rusjj.aml, 1.2.1)
END_DEPLIST()

uintptr_t pGame;
ConfigEntry* pCfgMyBestEntry;

extern "C" void OnModLoad()
{
    logger->SetTag("HUD Customizer");

    cfg->Bind("Author", "", "Main")->SetString("cheeseburger"); cfg->ClearLast();
    pGame = aml->GetLib("libGTASA.so");
    float healthLength = cfg->GetFloat("Health", 1000.0f, "Length");
    float healthWidth = cfg->GetFloat("Health", 0.095f, "Width");
    float healthPosY = cfg->GetFloat("Health", 0.455f, "PosY");
    float armorLength = cfg->GetFloat("Armor", 150.0f, "Length");
    float armorWidth = cfg->GetFloat("Armor", 0.095f, "Width");
    float armorPosY = cfg->GetFloat("Armor", 0.565f, "PosY");
    float breathLength = cfg->GetFloat("Breath", 150.0f, "Length");
    float breathWidth = cfg->GetFloat("Breath", 0.095f, "Width");
    float breathPosY = cfg->GetFloat("Breath", 0.675f, "PosY");
    float wantedMargin = cfg->GetFloat("Margin", -0.15f, "Wanted");
    float wantedBG = cfg->GetFloat("BGOpacity", 0.8f, "Wanted");
    float arrowScale = cfg->GetFloat("SwipeArrowScale", 0.2f, "WeaponScroll");
    float arrowScale2 = arrowScale * -1.0f;
    float clockPosY = cfg->GetFloat("Clock", 0.05f, "PosY");
    float clockmoneyPosX = cfg->GetFloat("ClockMoney", 0.55f, "PosX");
    float moneyPosY = cfg->GetFloat("Money", 0.255f, "PosY");
    float moneyScale = cfg->GetFloat("Money", 0.00525f, "TextScale");
    float ammoPosY = cfg->GetFloat("Ammo", 0.9f, "PosY");
    float ammoScale = cfg->GetFloat("Ammo", 0.425f, "TextScale");
    // Write configuration
    cfg->Bind("Health", healthLength, "Length")->GetFloat();
    cfg->Bind("Health", healthWidth, "Width")->GetFloat();
    cfg->Bind("Health", healthPosY, "PosY")->GetFloat();
    cfg->Bind("Armor", armorLength, "Length")->GetFloat();
    cfg->Bind("Armor", armorWidth, "Width")->GetFloat();
    cfg->Bind("Armor", armorPosY, "PosY")->GetFloat();
    cfg->Bind("Breath", breathLength, "Length")->GetFloat();
    cfg->Bind("Breath", breathWidth, "Width")->GetFloat();
    cfg->Bind("Breath", breathPosY, "PosY")->GetFloat();
    cfg->Bind("Margin", wantedMargin, "Wanted")->GetFloat();
    cfg->Bind("BGOpacity", wantedBG, "Wanted")->GetFloat();
    cfg->Bind("SwipeArrowScale", arrowScale, "WeaponScroll")->GetFloat();
    cfg->Bind("Clock", clockPosY, "PosY")->GetFloat();
    cfg->Bind("ClockMoney", clockmoneyPosX, "PosX")->GetFloat();
    cfg->Bind("Money", moneyPosY, "PosY")->GetFloat();
    cfg->Bind("Money", moneyScale, "TextScale")->GetFloat();
    cfg->Bind("Ammo", ammoPosY, "PosY")->GetFloat();
    cfg->Bind("Ammo", ammoScale, "TextScale")->GetFloat();

    delete pCfgMyBestEntry;
    delete Config::pLastEntry;
    cfg->Save();


    if(cfg->GetBool("Enable", true, "Main"))
    {
        // Health
        aml->WriteFloat(pGame + 0x2BD7B8, healthLength);
        aml->WriteFloat(pGame + 0x2BD7C0, healthWidth);
        aml->WriteFloat(pGame + 0x2BD5DC, healthPosY);
        // Armor
        aml->WriteFloat(pGame + 0x2BD94C, armorLength);
        aml->WriteFloat(pGame + 0x2BD954, armorWidth);
        aml->WriteFloat(pGame + 0x2BD5E4, armorPosY);
        // Breath
        aml->WriteFloat(pGame + 0x2BDA8C, breathLength);
        aml->WriteFloat(pGame + 0x2BDA84, breathWidth);
        aml->WriteFloat(pGame + 0x2BD5F8, breathPosY);
        // Weapon Scroll
        aml->WriteFloat(pGame + 0x2BD010, arrowScale);
        aml->WriteFloat(pGame + 0x2BD00C, arrowScale2);
        // Money
        aml->WriteFloat(pGame + 0x2BD5D8, moneyPosY);
        aml->WriteFloat(pGame + 0x2BD028, moneyScale);
        // Ammo
        aml->WriteFloat(pGame + 0x2BDF40, ammoPosY);
        aml->WriteFloat(pGame + 0x2BDF3C, ammoScale);
        // Clock
        aml->WriteFloat(pGame + 0x2BD024, clockPosY);
        // Pos X of Clock & Money
        aml->WriteFloat(pGame + 0x2BD020, clockmoneyPosX);
    }
}

