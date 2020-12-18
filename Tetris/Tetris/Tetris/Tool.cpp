#include <random>
#include "Tool.h"

int Tool::GenerateRandomNumber()
{
	// �õ� ���� ��� ���� ���� ����̽� ����.
	std::random_device RandomDevice;

	// �ռ� ������ ���� ����̽��� ���� ���� ���� �ʱ�ȭ.
	std::mt19937 Generator( RandomDevice() );

	// ��𿡼� ������ �̾Ƴ��� �˷��ִ� ������ ����. (�յ� ����)
	std::uniform_int_distribution<int> Distribution( 1, 7 );

	// �յ� ���� ��ü�� ����� ���� ������ �����Ͽ� �յ� �������� �������� ������ ����.
	return Distribution( Generator );
}
